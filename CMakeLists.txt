cmake_minimum_required(VERSION 3.3)
project(Pairing_Primes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp PairFinder.h)
add_executable(Pairing_Primes ${SOURCE_FILES})