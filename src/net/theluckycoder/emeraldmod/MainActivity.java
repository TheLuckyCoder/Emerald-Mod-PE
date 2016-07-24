package net.theluckycoder.emeraldmod;

import android.*;
import android.app.Activity;
import android.os.Bundle;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

import com.razvanmcrafter.addon.emeraldmod.R;

public class MainActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
    }

    public void hideApp(View view) {
		PackageManager pm = getPackageManager();
		pm.setComponentEnabledSetting(getComponentName(), PackageManager.COMPONENT_ENABLED_STATE_DISABLED, PackageManager.DONT_KILL_APP);
	}

	public void downloadBL(View view) {
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
