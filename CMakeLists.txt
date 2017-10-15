cmake_minimum_required(VERSION 3.2)

project(HackCV)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.(h|hpp)")

add_executable(HackCV ${SOURCE_FILES})

# пакет конана OpenCV сделан с ошибкой, добавлена несуществующая либа shared
foreach(loop_var ${CONAN_LIBS})
    if(NOT ${loop_var} STREQUAL shared)
        SET(LIBS  ${LIBS} ${loop_var})
    endif()
endforeach(loop_var)

target_link_libraries(HackCV ${LIBS})

#target_link_libraries(HackCV ${OpenCV_LIBS})
