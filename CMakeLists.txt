cmake_minimum_required(VERSION 3.2)

project(HackCV)

set(OPENCV_SOURCE_DIR ${CMAKE_BINARY_DIR}/externals/OpenCV)
set(OPENCV_BINARY_DIR ${CMAKE_BINARY_DIR}/externals/OpenCV-build)

file(GLOB OPENCV_SOURCE_FILES ${OPENCV_SOURCE_DIR})
if(NOT OPENCV_SOURCE_FILES)
    file(DOWNLOAD
        https://github.com/opencv/opencv/archive/master.zip
        ${CMAKE_BINARY_DIR}/externals/OpenCV/OpenCV.zip SHOW_PROGRESS
    )

    execute_process(
        COMMAND ${CMAKE_COMMAND} -E tar xf OpenCV.zip
        WORKING_DIRECTORY ${OPENCV_SOURCE_DIR}
        RESULT_VARIABLE OPENCV_EXTRUCT_RESULT
    )
endif(NOT OPENCV_SOURCE_FILES)

file(MAKE_DIRECTORY ${OPENCV_BINARY_DIR})
execute_process(
    COMMAND ${CMAKE_COMMAND} ${OPENCV_SOURCE_DIR}/opencv-master
                             -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    WORKING_DIRECTORY ${OPENCV_BINARY_DIR}
    RESULT_VARIABLE OPENCV_EXTRUCT_RESULT
)
execute_process(
    COMMAND ${CMAKE_COMMAND} --build .
    WORKING_DIRECTORY ${OPENCV_BINARY_DIR}
    RESULT_VARIABLE OPENCV_EXTRUCT_RESULT
)

find_library(OPENCV_LIBS opencv_code PATHS ${OPENCV_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE})
find_package(OpenCV REQUIRED)

message(STATUS ${OPENCV_LIBS})

include_directories(${OpenCV_INCLUDE_DIR})

file(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.(h|hpp)")

add_executable(HackCV ${SOURCE_FILES})
#target_link_libraries(HackCV ${OpenCV_LIBS})
