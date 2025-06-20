# 🧪 Edge Detection Viewer – Android + OpenCV-C++ + JNI

This is a minimal Android app that captures real-time camera frames, sends them to native C++ code via JNI, processes them using OpenCV (Canny Edge Detection), and renders the result back onto the screen.

---

## 📱 Preview

| Camera Feed | Edge Detection |
|-------------|----------------|
| Coming soon | Coming soon    |

---

## 🔧 Tech Stack

- **Android SDK (Java)**
- **OpenCV (C++)**
- **NDK / JNI**
- **TextureView + Camera2 API**
- **CMake**

---

## ⚙️ Features

- Live camera feed using `TextureView`
- Real-time edge detection using **OpenCV Canny algorithm**
- Frame processing through **JNI (Java → C++)**
- Render output directly onto TextureView

---

## 📂 Project Structure

EdgeDetectionApp/
├── app/
│ ├── src/
│ │ ├── main/
│ │ │ ├── cpp/ # C++ code (OpenCV processing)
│ │ │ ├── java/com/shubham/… # Java code (Camera & JNI)
│ │ │ ├── res/layout/ # activity_main.xml
│ │ │ └── AndroidManifest.xml
│ ├── build.gradle.kts
├── CMakeLists.txt
└── README.md


---

## 🚀 Setup Instructions

### ✅ 1. Clone the Repository
```bash
git clone https://github.com/your-username/edge-detection-app.git
cd edge-detection-app

✅ 2. Download & Set Up OpenCV SDK
Download OpenCV Android SDK

Extract the SDK.

Set this path in your CMakeLists.txt:

cmake
Copy
Edit
set(OpenCV_DIR path/to/OpenCV-android-sdk/sdk/native/jni)
🔁 Sync project with Gradle after this.

✅ 3. Build Configuration (build.gradle.kts)
Make sure you have:

kotlin
Copy
Edit
defaultConfig {
    ...
    ndk {
        abiFilters += listOf("armeabi-v7a", "arm64-v8a")
    }
}

externalNativeBuild {
    cmake {
        path = file("src/main/cpp/CMakeLists.txt")
        version = "3.22.1"
    }
}
✅ 4. Permissions
Add this to AndroidManifest.xml:

xml
Copy
Edit
<uses-permission android:name="android.permission.CAMERA" />
✅ 5. Run on Physical Device or ARM64 Emulator
⚠️ NDK builds support armeabi-v7a and arm64-v8a, not x86.

🧠 Architecture
TextureView → receives frames from Camera2

onSurfaceTextureUpdated() → captures frame as Bitmap

JNI → sends Bitmap to native-lib.cpp

OpenCV → applies Canny Edge Detection

Bitmap is updated directly with edges

📈 TODOs / Next Steps
 Use OpenGL for rendering output

 Add toggle button: Original vs Processed

 Add FPS counter

 Add Gaussian blur / Thresholding

🧑‍💻 Author
Shubham Mali
B.Tech, IIIT Bhopal
[LinkedIn](https://www.linkedin.com/in/shubham1144/)
 – GitHub

📜 License
MIT License – free to use and modify.


---

Let me know your GitHub repo link (if ready), and I can personalize the clone/setup parts for you. Or I can generate a `README.md` file you can directly drop into your project folder.
