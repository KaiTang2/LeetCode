# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("LeetCodeProject")
project ("Question1")
project ("Question59")
project ("Question115")

# 包含子项目。
add_subdirectory ("LeetCodeProject")
add_subdirectory ("Question1")
add_subdirectory ("Question59")
add_subdirectory ("Question115")
