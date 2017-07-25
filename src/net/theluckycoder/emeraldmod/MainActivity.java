package net.theluckycoder.emeraldmod;

import android.Manifest;
import android.app.Activity;
import android.os.Bundle;
import android.os.Build;
import android.content.Intent;
import android.net.Uri;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;
import android.content.pm.PackageManager;
import android.content.pm.PackageInfo;
import android.widget.TextView;
import android.util.Log;
import android.text.Html;

import com.razvanmcrafter.addon.emeraldmod.R;

public class MainActivity extends Activity {
	
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
		
		if (Build.VERSION.SDK_INT >= 23) 
			checkForPermission();
			
		TextView supportedVersion = (TextView) findViewById(R.id.supportedVersionTxt);
		TextView installedVersion = (TextView) findViewById(R.id.installedVersionTxt);
		
		supportedVersion.setText(Html.fromHtml(getText(R.string.supports_version) + " <b>" + getText(R.string.supported_version_number) + "</b>"));
		
		PackageInfo pInfo;
		try
		{
			pInfo = getPackageManager().getPackageInfo("com.mojang.minecraftpe", 0);
			String verName = pInfo.versionName;
			installedVersion.setText(Html.fromHtml(getText(R.string.installed_version) + " <b>" + verName + "</b>"));
		} catch (PackageManager.NameNotFoundException e) {
			installedVersion.setVisibility(View.GONE);
			Log.e("EmeraldModApp", "Could not rethrive MC version", e);
		}
    }

	public void downloadLauncher(View view) {
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
				return true;
			case R.id.community:
				startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("https://plus.google.com/communities/104130537090639033736")));
				return true;
			case R.id.twitter:
				startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("https://twitter.com/theluckycoder")));
				return true;
			default:  
                return super.onOptionsItemSelected(item);  
        }
    }

    private void checkForPermission() {
		if (checkSelfPermission("net.zhuoweizhang.mcpelauncher.ADDON") != PackageManager.PERMISSION_GRANTED)
			requestPermissions(new String[] {"net.zhuoweizhang.mcpelauncher.ADDON"}, 123);
    }
}

