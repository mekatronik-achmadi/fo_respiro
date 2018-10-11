package com.example.Test;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.io.IOException;
import java.io.OutputStream;
import java.util.UUID;

public class TestActivity extends Activity {

    /*
    Deklarasi variabel dan objek untuk satu class
     */
    // Bluetooth related
    private static final int REQUEST_ENABLE_BT = 1;
    private BluetoothAdapter btAdapter=null;
    private BluetoothSocket btSocket=null;
    private OutputStream outStream=null;

    private static final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");
    private static String addressbt = "00:00:00:00:00:00";

    // Widget
    TextView txtOut;
    Button btnConnect;

    /*
    Rutin tambahan
     */
    private void Pesan(String txtpesan){
        Context context = getApplicationContext();
        int duration = Toast.LENGTH_SHORT;

        Toast toast = Toast.makeText(context,txtpesan,duration);

        toast.setGravity(Gravity.CENTER,0,0);
        toast.show();
    }

    private void CheckStateBT(){
        if(btAdapter==null){
            Pesan("Fatal Error: Bluetooth Not supported. Aborting.");
        }
        else{
            if (btAdapter.isEnabled()){
                txtOut.append("\n...Bluetooth is enabled...");
            }
            else{
                Intent enablingBT = new Intent(btAdapter.ACTION_REQUEST_ENABLE);
                startActivityForResult(enablingBT,REQUEST_ENABLE_BT);
            }
        }
    }

    private void ConnectBT(){
        BluetoothDevice devBT = btAdapter.getRemoteDevice(addressbt);

        txtOut.append("\n...connecting to target...");
        try{
            btSocket = devBT.createRfcommSocketToServiceRecord(MY_UUID);
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

        try{
            outStream = btSocket.getOutputStream();
        }catch(IOException e){
            String pesanerror = "Fatal Error: out stream creation failed: " + e.getMessage() + ".";
            Pesan(pesanerror);
        }

    }

    /*
    Aktifitas Intent
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        //Widget Creation
        txtOut = (TextView) findViewById(R.id.txtOut);
        btnConnect = (Button) findViewById(R.id.btnConnect);

        //Bluetooth Creation
        btAdapter = BluetoothAdapter.getDefaultAdapter();
        CheckStateBT();

        btnConnect.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                ConnectBT();
            }
        });
    }

    public void onStart(){
        super.onStart();
        txtOut.append("\n...In onStart()...");
    }


}
