cmake_minimum_required(VERSION 3.0)
project(base)
#mymuduo最终编译成so动态库，设置动态库的路径,放在根目录的lib文件夹下面
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

set(SUB_DIR_LIST "utils")

foreach(SUB_DIR ${SUB_DIR_LIST})
    aux_source_directory(${SUB_DIR} SRC_LIST)
endforeach()

add_library(base STATIC ${SRC_LIST})