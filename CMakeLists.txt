cmake_minimum_required(VERSION 3.26)
project(HashMaps)

set(CMAKE_CXX_STANDARD 14)

include_directories(HashMapProject)

add_executable(HashMaps
        HashMapProject/HashMap.cpp
        HashMapProject/HashMap.hpp
        HashMapProject/HashNode.cpp
        HashMapProject/HashNode.hpp
        HashMapProject/mainHash.cpp
        HashMapProject/MakeModel.cpp
        HashMapProject/MakeModel.hpp)
