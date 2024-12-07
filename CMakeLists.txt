cmake_minimum_required(VERSION 3.23)
project(zero_media_server)

#设置调试信息并开启c++11标准
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3 -std=c++11")

set(LINK_LIB_LIST base)
# 添加源文件目录
add_subdirectory(base)
add_subdirectory(test)

add_executable(main main.cpp)
target_link_libraries(main ${LINK_LIB_LIST}  pthread)
# 启用测试支持
enable_testing()

