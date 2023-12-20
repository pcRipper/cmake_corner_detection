cmake_minimum_required(VERSION 3.28.1)
project(cmake_corner_detection VERSION 1.0)

#OpenCV
set(OPENCV_PATH "D://code//cpp//libraries")
find_package(OpenCV REQUIRED PATHS "${OPENCV_PATH}//opencv//build//x64//vc16//lib")
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cmake_corner_detection main.cpp)

#Local code
#include headers
target_include_directories(cmake_corner_detection PRIVATE ./bin/Headers)
#include source files
file(GLOB_RECURSE SRC_FILES
    ./bin/Source/*.cpp
)
target_sources(cmake_corner_detection PRIVATE ${SRC_FILES})

#OpenCV
target_link_libraries(cmake_corner_detection PRIVATE ${OpenCV_LIBS})
