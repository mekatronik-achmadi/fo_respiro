package com.example.Test;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class TestActivity extends Activity {
    /**
     * Called when the activity is first created.
     */
    public void Pesan(CharSequence txtpesan){
        Context context = getApplicationContext();
        int duration = Toast.LENGTH_SHORT;

        Toast toast = Toast.makeText(context,txtpesan,duration);

        toast.setGravity(Gravity.CENTER,0,0);
        toast.show();
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        Button btnPesan = (Button) findViewById(R.id.btnPesan);

        btnPesan.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Pesan("I'm in Love (Fake Love)");
            }
        });
    }
}
