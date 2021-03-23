# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("LeetCodeProject")
project ("Question")
project ("Question1")
project ("Question59")
project ("Question73")
project ("Question92")
project ("Question115")
project ("Question150")
project ("Question191")
project ("Question303")
project ("Question341")
project ("Question398")
project ("Question1759")

# inerview question
project ("InterviewQuestion/0206")

# 包含子项目。
add_subdirectory ("LeetCodeProject")
add_subdirectory ("Question")
add_subdirectory ("Question1")
add_subdirectory ("Question59")
add_subdirectory ("Question73")
add_subdirectory ("Question92")
add_subdirectory ("Question115")
add_subdirectory ("Question150")
add_subdirectory ("Question191")
add_subdirectory ("Question303")
add_subdirectory ("Question341")
add_subdirectory ("Question398")
add_subdirectory ("Question1759")


add_subdirectory ("InterviewQuestion/0206")
