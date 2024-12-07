#enable_testing()
#
#set(LINK_LIB_LIST base)
## 添加源文件目录
#add_subdirectory(base)
#
#add_executable(test_thread Test_Thread.cpp base/utils/Thread.h base/utils/Thread.cpp)
#target_link_libraries(${LINK_LIB_LIST}  pthread)
#
#add_test(test_Thread test_thread)
## 添加 Google Test 作为测试框架
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
#
## 添加测试源文件
#add_executable(test_my_project test_main.cpp)
#
## 链接 Google Test 库
#target_link_libraries(test_my_project GTest::GTest GTest::Main)
#
## 添加测试
#add_test(NAME MyProjectTests COMMAND test_my_project)


#cmake_minimum_required(VERSION 3.0)
#project(test)

# 添加测试源文件
#add_executable(test_thread Test_Thread.cpp Test_List.cpp)
add_executable(tests Test_Logger.cpp)
# 链接基础库和 pthread 库
target_link_libraries(tests base pthread)

# 添加测试
add_test(NAME test COMMAND tests)
