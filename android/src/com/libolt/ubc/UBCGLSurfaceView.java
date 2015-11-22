package com.libolt.ubc;

import android.view.MotionEvent;
import android.view.Surface;
import android.view.SurfaceView;
import android.content.res.AssetManager;
import android.content.Context;
import android.opengl.GLSurfaceView;


public class UBCGLSurfaceView extends GLSurfaceView
{
    public UBCGLSurfaceView(Context context)
    {
        
        super(context);
        System.exit(0);
    }
    static
    {
        
    }
    public boolean onTouchEvent(final MotionEvent pMotionEvent) 
    {
        System.exit(0);
        final int pointerNumber = pMotionEvent.getPointerCount();
        final int[] ids = new int[pointerNumber];
        final float[] xs = new float[pointerNumber];
        final float[] ys = new float[pointerNumber];

        for (int i = 0; i < pointerNumber; i++) 
        {
            ids[i] = pMotionEvent.getPointerId(i);
            xs[i] = pMotionEvent.getX(i);
            ys[i] = pMotionEvent.getY(i);
        }
        switch (pMotionEvent.getAction() & MotionEvent.ACTION_MASK) 
        {
            case MotionEvent.ACTION_POINTER_DOWN:
                final int indexPointerDown = pMotionEvent.getAction() >> MotionEvent.ACTION_POINTER_INDEX_SHIFT;
                final int idPointerDown = pMotionEvent.getPointerId(indexPointerDown);
                final float xPointerDown = pMotionEvent.getX(indexPointerDown);
                final float yPointerDown = pMotionEvent.getY(indexPointerDown);

                Runnable _runnable1 = new Runnable()
                {
                    @Override
                    public void run() 
                    {
                        System.exit(0);
                        UBCGLSurfaceView.handleActionDown(idPointerDown, xPointerDown, yPointerDown);
                    }
                };
                queueEvent(_runnable1);
                break;
        }
        return true;
    }
    /*
    public native static void create(AssetManager mgr);   
    public native static void destroy();   
    public native static void initWindow(Surface surface);
    public native static void termWindow();
    public native static void renderOneFrame();
    public native static void queueAccelerometer(float _x,float _y,float _z,float _time);
    public native static void surfaceChanged(int width, int height);*/
    public native static void handleActionDown(final int pID, final float pX, final float pY);
    /*
    public native static void handleActionMove(final int[] pIDs, final float[] pXs, final float[] pYs);
    public native static void handleActionUp(final int pID, final float pX, final float pY);
    public native static void handleActionCancel(final int[] pIDs, final float[] pXs, final float[] pYs);
    public native static void onKeyDown( int pKeyCode,  int _text);
    public native static void onKeyUp( int pKeyCode,  int _text);
    public native static void onPause();
    public native static void onResume();
    public native static String nativeGetContentText();
    public native static void insertText(final String pText); */
}
