cmake_minimum_required(VERSION 3.0.0)
project(ocvGPUtest VERSION 0.1.0)

include(CTest)
enable_testing()

#set("OpenCV_DIR" "G:/opencv/build/install/x64/vc17/lib")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(ocvGPUtest main.cpp)

target_link_libraries( ocvGPUtest ${OpenCV_LIBS} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)