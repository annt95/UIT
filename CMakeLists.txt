cmake_minimum_required(VERSION 3.16)
project(UIT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(d1_2 DSA/D1/D1_2.cpp
        DSA/D2/Bai1.cpp
        DSA/D2/Bai1.h
        DSA/D2/D2_2.cpp
        DSA/D2/D2_2.h
        DSA/D2/D2_3.cpp)
add_executable(D1_demo OOP/D1/D1_demo.cpp)

add_executable(oop_bai1 OOP/D1/Bai1.cpp)
add_executable(oop_bai2 OOP/D1/Bai2.cpp)
add_executable(oop_bai3 OOP/D1/Bai3.cpp)
add_executable(oop_bai4 OOP/D1/Bai4.cpp)
add_executable(oop_bai5 OOP/D1/Bai5.cpp)
add_executable(oop_bai6 OOP/D1/Bai6.cpp)
add_executable(oop_bai7 OOP/D1/Bai7.cpp)
add_executable(oop_bai8 OOP/D1/Bai8.cpp)
add_executable(KT15p OOP/D1/KT15p.cpp)