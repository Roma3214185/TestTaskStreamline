cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
project(Task2)

add_library(refactor_task
        IndexError.h
        main.cpp

        task2_1/stringlist.h
        task2_1/stringlist.inl

        task2_2/stringlist2.cpp
        task2_2/stringlist2.h
)

add_executable(task2 main.cpp  task2_2/stringlist2.cpp)

target_link_directories(task2 PRIVATE refactor_task)