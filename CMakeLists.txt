cmake_minimum_required(VERSION 3.16)
project(UIT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(d1_1 DSA/D1/D1_1.cpp)
add_executable(TH01 DSA/D4/TH01.cpp
        DSA/TH01/D2/b2.cpp
        DSA/TH01/D2/b2.h
        DSA/TH01/D2/b3.cpp
        DSA/TH01/D2/b3.h
        DSA/D4/TH02.cpp
        DSA/D4/TH03.cpp)
add_executable(d1_2 DSA/D1/D1_2.cpp)
add_executable(d1_3 DSA/D1/D1_3.cpp)
add_executable(d1_4 DSA/D1/D1_4.cpp)
add_executable(d1_5 DSA/D1/D1_5.cpp)

add_executable(D2_Bai1 DSA/D2/Bai1.cpp)
add_executable(D2_2 DSA/D2/D2_2.cpp)
add_executable(D2_3 DSA/D2/D2_3.cpp)
add_executable(D3_demo DSA/D3/D3_Demo.cpp)

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

add_executable(OOP_D2_demo OOP/D2/D2_Demo.cpp)
