cmake_minimum_required(VERSION 3.21)
project(cycle_queue C)

set(CMAKE_C_STANDARD 11)

add_executable(cycle_queue queue.c main.c)
