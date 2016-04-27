package com.razvanmcrafter.addon.emeraldmod;

import android.*;
import android.app.*;
import android.content.*;
import android.content.pm.*;
import android.net.*;
import android.os.*;
import android.view.*;
import android.widget.*;

public class MainActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
	
    public void hideApp (View view){
		PackageManager p = getPackageManager();
		p.setComponentEnabledSetting(getComponentName(),
									 PackageManager.COMPONENT_ENABLED_STATE_DISABLED,
									 PackageManager.DONT_KILL_APP);
	}
	
	public void downloadBL (View view){
		startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("https://play.google.com/store/apps/details?id=net.zhuoweizhang.mcpelauncher")));
	}
	
	@Override  
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }
    @Override  
    public boolean onOptionsItemSelected(MenuItem item) {  
        switch (item.getItemId()) {  
            case R.id.checkTwitter:
				startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("https://twitter.com/razvan_145?s=09")));
				return true;
			case R.id.rate:
                startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("https://play.google.com/store/apps/details?id=com.razvanmcrafter.addon.emeraldmod")));
				Toast.makeText(getApplicationContext(),"Thank you for the 5 star rating",Toast.LENGTH_SHORT).show();
				return true; 
			case R.id.community:
				startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("https://plus.google.com/communities/104130537090639033736")));
				return true;
			default:  
                return super.onOptionsItemSelected(item);  
        }  
    }  
}
