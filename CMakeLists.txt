cmake_minimum_required(VERSION 3.31)
project(task_scheduler)

set(CMAKE_CXX_STANDARD 20)

add_executable(task_scheduler main.cpp
        Task.cpp
        Task.h
        Scheduler.cpp
        Scheduler.h
        main.cpp
)
