cmake_minimum_required(VERSION 3.28.1)

project(cmake_corner_detection VERSION 1.0)
set(OPENCV_PATH "D://code//cpp//libraries//opencv//build//x64//vc16//lib")

find_package(OpenCV REQUIRED PATHS "${OPENCV_PATH}")
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cmake_corner_detection main.cpp)

target_link_libraries(cmake_corner_detection PRIVATE ${OpenCV_LIBS})
