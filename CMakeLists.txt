cmake_minimum_required(VERSION 3.26)
project(lists)

set(CMAKE_CXX_STANDARD 17)

add_executable(lists main.cpp
        Single_node.h
        Single_list.h
        Double_node.h
        Double_list.h
        Queue.h
        Queue_node.h
        Queue_arr.h)
