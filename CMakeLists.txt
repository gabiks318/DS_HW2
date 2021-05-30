cmake_minimum_required(VERSION 3.17)
project(DS_HW2)

set(CMAKE_CXX_STANDARD 11)

add_executable(DS_HW2 main.cpp CarAgenciesManager.cpp UnionFindAgency.cpp CarType.cpp library.cpp)

add_subdirectory("./tests")