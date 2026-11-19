cmake_minimum_required(VERSION 3.20)
project(SimSET_test LANGUAGES C)

find_package(SimSET REQUIRED)

add_executable(use_simset use_simset.c)
target_link_libraries(use_simset SimSET::simset)