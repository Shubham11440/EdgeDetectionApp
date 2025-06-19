#include <jni.h>
#include <android/bitmap.h>       // ✅ Required for AndroidBitmap_*
#include <opencv2/opencv.hpp>

using namespace cv;

extern "C"
JNIEXPORT void JNICALL
Java_com_shubham_edgedetectionapp_MainActivity_processFrameNative(
        JNIEnv* env, jobject, jobject bitmap) {

    AndroidBitmapInfo info;
    void* pixels = nullptr;

    if (AndroidBitmap_getInfo(env, bitmap, &info) < 0) return;
    if (info.format != ANDROID_BITMAP_FORMAT_RGBA_8888) return;
    if (AndroidBitmap_lockPixels(env, bitmap, &pixels) < 0) return;

    // Convert bitmap to Mat
    Mat rgba(info.height, info.width, CV_8UC4, pixels);

    // Convert to grayscale
    Mat gray;
    cvtColor(rgba, gray, COLOR_RGBA2GRAY);

    // Apply Canny Edge Detection
    Mat edges;
    Canny(gray, edges, 100, 200);

    // Convert back to 4-channel RGBA for drawing on original bitmap
    Mat edgesColor;
    cvtColor(edges, edgesColor, COLOR_GRAY2RGBA);

    // Copy edges result into original bitmap
    edgesColor.copyTo(rgba);

    AndroidBitmap_unlockPixels(env, bitmap);
}
