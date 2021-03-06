package com.example.Test;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.method.ScrollingMovementMethod;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.softmoore.android.graphlib.Graph;
import com.softmoore.android.graphlib.GraphView;
import com.softmoore.android.graphlib.Point;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.lang.reflect.Method;
import java.util.UUID;

public class TestActivity extends Activity {

/****************************************************************/
/* Deklarasi                                                    */
/****************************************************************/

    // Bluetooth related
    private BluetoothAdapter btAdapter=null;
    private BluetoothSocket btSocket=null;
    private StringBuilder sb = new StringBuilder();

    private static final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");
    private static final String addressbt = "98:D3:32:21:44:6E";

    private ConnectedThread mConnectedThread;
    final int RECIEVE_MESSAGE = 1;
    int REQ_LOCK;
    Handler hdl;

    private Runnable datreq;
    Handler hreq;

     // Widget
    TextView txtOut;
    TextView txtData;
    Button btnConnect;
    Button btnStart;

    // Graph

    GraphView grpview;
    Graph graph;

    int datanmax=200;
    Point[] datadot;
    double vy=0;
    double[] val_y;

    String strData;
    int vData;

/****************************************************************/
/* AKtifitas Utama                                              */
/****************************************************************/
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        //Widget Creation
        btnConnect = (Button) findViewById(R.id.btnConnect);
        btnStart = (Button) findViewById(R.id.btnStart);
        txtData = (TextView) findViewById(R.id.txtData);
        txtOut = (TextView) findViewById(R.id.txtOut);
        txtOut.setMovementMethod(new ScrollingMovementMethod());

        // Graph Function
        datadot = new Point[datanmax];
        val_y = new double[datanmax];

        data_zeroing();
        graph = new Graph.Builder()
                .addLineGraph(datadot)
                .setWorldCoordinates(-1, datanmax, -1, 200)
                .setXTicks(new double[] {0})
                .setYTicks(new double[] {0})
                .build();
        grpview = (GraphView) findViewById(R.id.grpview);
        grpview.setGraph(graph);

        // Bluetooth Function

        hdl = new Handler(){
            public void handleMessage(Message msg){
                switch (msg.what){
                    case RECIEVE_MESSAGE:
                        byte[] readbuf = (byte[]) msg.obj;
                        String strInComm = new String(readbuf,0,msg.arg1);
                        sb.append(strInComm);

                        int eolIndex = sb.indexOf("\n\r");
                        if(eolIndex > 0) {
                            String sbprint = sb.substring(0,eolIndex);
                            sb.delete(0,sb.length());
                            txtData.setText(sbprint);
                        }

                        data_graph();

                        break;
                }
            }
        };

        hreq = new Handler();
        datreq = new Runnable() {
            @Override
            public void run() {
                DataRequest();
                hreq.postDelayed(this,100);
            }
        };

        //Bluetooth Creation
        btAdapter = BluetoothAdapter.getDefaultAdapter();
        CheckStateBT();

        btnConnect.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                ConnectBT();
            }
        });

        btnStart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                txtOut.append("\n...Data Request Start...");
                hreq.post(datreq);
                btnStart.setEnabled(false);
            }
        });

    }

    @Override
    public void onStart(){
        super.onStart();
        txtOut.append("\n...Addr: " + addressbt + "...");
        txtOut.append("\n...UUID: " + MY_UUID + "...");
    }

/****************************************************************/
/* Rutin tambahan                                               */
/****************************************************************/
    private void Pesan(String txtpesan){
        Context context = getApplicationContext();
        int duration = Toast.LENGTH_SHORT;

        Toast toast = Toast.makeText(context,txtpesan,duration);

        toast.setGravity(Gravity.CENTER,0,0);
        toast.show();
    }

    private void data_zeroing(){
        vy = 0;
        for(int i=0; i<datanmax; i++){
            datadot[i] = new Point(i,0);
            val_y[i] = vy;
        }
    }

    private void data_shifting(){
        for(int i=datanmax-1; i>0; i--){
            vy = val_y[i-1];
            val_y[i] = vy;
            datadot[i] = new Point(i,vy);
        }
    }

    private void data_graph(){
        strData = txtData.getText().toString().trim();
        if(strData.length()>0){

            String[] arrStrData=strData.split(",");
            if(arrStrData.length > 2){
                vData = Integer.parseInt(arrStrData[2].trim());

                data_shifting();

                vy = vData;
                val_y[0] = vy;
                datadot[0] = new Point(0,vy);

                grpview.setGraph(graph);
            }

            REQ_LOCK = 0;
        }
    }

/****************************************************************/
/* Rutin Bluetooth                                              */
/****************************************************************/

    private BluetoothSocket createBluetoothSocket(BluetoothDevice dev) throws IOException{
        if(Build.VERSION.SDK_INT >= 10){
            try{
                final Method m = dev.getClass().getMethod("createInsecureRfcommSocketToServiceRecord",new Class[] {UUID.class});
                return (BluetoothSocket) m.invoke(dev,MY_UUID);
            }catch (Exception e){
                String pesanerror = "Could not create Insecure RFComm Connection" + e.getMessage() + ".";
                Pesan(pesanerror);
            }
        }
        return dev.createRfcommSocketToServiceRecord(MY_UUID);
    }

    private void CheckStateBT(){
        if(btAdapter==null){
            Pesan("Fatal Error: Bluetooth Not supported. Aborting.");
        }
        else{
            if (!btAdapter.isEnabled()){
                Intent enablingBT = new Intent(btAdapter.ACTION_REQUEST_ENABLE);
                startActivityForResult(enablingBT,1);
            }
        }
    }

    private void ConnectBT(){
        BluetoothDevice devBT = btAdapter.getRemoteDevice(addressbt);

        try{
            btSocket = createBluetoothSocket(devBT);
        }catch (IOException e){
            String pesanerror = "Fatal Error: socket creation failed: " + e.getMessage() + ".";
            Pesan(pesanerror);
        }

        btAdapter.cancelDiscovery();

        try{
            btSocket.connect();
        }catch (IOException e){

            try{
                btSocket.close();
                String pesanerror = "Fatal Error: connection creation failed: " + e.getMessage() + ".";
                Pesan(pesanerror);
            }catch(IOException e2){
                String pesanerror = "Fatal Error: connection closing failed: " + e2.getMessage() + ".";
                Pesan(pesanerror);
            }
        }

        btnConnect.setEnabled(false);

        mConnectedThread = new ConnectedThread(btSocket);
        mConnectedThread.start();

        txtOut.append("\n...Bluetooth Connected...");
        btnStart.setEnabled(true);
    }

    private void DataRequest(){
        if(REQ_LOCK == 0) {
            REQ_LOCK = 1;
            txtData.setText("");
            mConnectedThread.write("adc0\n\r");
        }
    }

/****************************************************************/
/* Thread tambahan                                              */
/****************************************************************/
    private class ConnectedThread extends Thread {
        private final InputStream mmInStream;
        private final OutputStream mmOutStream;

        public ConnectedThread(BluetoothSocket socket){
            InputStream tmpIn = null;
            OutputStream tmpOut = null;

            try{
                tmpIn = socket.getInputStream();
                tmpOut = socket.getOutputStream();
            }catch(IOException e){}

            mmInStream = tmpIn;
            mmOutStream = tmpOut;
        }

        public void run(){
            byte[] buffer = new byte[256];
            int bytes;

            while(true){
                try{
                    bytes = mmInStream.read(buffer);
                    hdl.obtainMessage(RECIEVE_MESSAGE,bytes,-1,buffer).sendToTarget();
                }catch (IOException e){
                    break;
                }
            }
        }

        public void write(String msg){
            byte[] msgbuffer = msg.getBytes();
            try{
                mmOutStream.write(msgbuffer);
            }catch(IOException e){}
        }

    }

/****************************************************************/
/* END OF MAIN CLASS                                            */
/****************************************************************/
}
