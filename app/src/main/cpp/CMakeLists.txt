cmake_minimum_required(VERSION 3.22.1)
project("edgedetectionapp")

# 👇 Update this path to your OpenCV SDK path (adjust slashes)
set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/../OpenCV/sdk/native/jni)

find_package(OpenCV REQUIRED)

add_library(native-lib SHARED native-lib.cpp)

target_include_directories(native-lib PRIVATE ${OpenCV_INCLUDE_DIRS})

find_library(log-lib log)
find_library(jnigraphics-lib jnigraphics)

target_link_libraries(native-lib
        ${log-lib}
        ${jnigraphics-lib}
        ${OpenCV_LIBS})
