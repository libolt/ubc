package com.libolt.ubc;

import org.libsdl.app.SDLActivity;
public class UBCActivity extends SDLActivity
{
    public static native void onTouch();
	static 
	{
        System.loadLibrary("openal");
//        System.loadLibrary("almixer");
        System.loadLibrary("UltimateBasketballChallenge");
    }	
    
}

    
