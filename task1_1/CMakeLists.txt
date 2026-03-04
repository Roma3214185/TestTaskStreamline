cmake_minimum_required(VERSION 3.20)
project(test_task)

set(CMAKE_CXX_STANDARD 20)

add_library(repository
        ItemRepository.cpp
        ItemRepository.h
        Item.h
        utils.cpp
        utils.h
)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)


add_executable(test_task main.cpp)
add_executable(test_repository tests/repository_tests.cpp)

target_link_libraries(test_task PRIVATE repository)
target_link_libraries(test_repository PRIVATE repository gtest gtest_main)
