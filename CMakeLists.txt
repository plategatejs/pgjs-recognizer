cmake_minimum_required(VERSION 2.8.4)
project(PlateRecognitionServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/ALPRHandler.cpp
    src/QueueHandler.cpp
    src/PlateRecognitionServer.cpp)

include_directories (
    /usr/local/include/opencv
    src/include
)

link_directories (
    /usr/local/lib
)
set ( OPENCV_LIBRARIES
    opencv_core
    opencv_imgproc
    opencv_highgui
	openalpr
)

add_executable(FallDetectionTestingTemplate ${SOURCE_FILES})
target_link_libraries( FallDetectionTestingTemplate ${OPENCV_LIBRARIES})
