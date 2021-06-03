cmake_minimum_required(VERSION 3.17)
project(DS_HW2)

set(CMAKE_CXX_STANDARD 11)

add_executable(DS_HW2 tests/avl_tests.cpp CarAgenciesManager.cpp UnionFindAgency.cpp CarType.cpp CarSales.cpp library.cpp)

add_subdirectory("./tests")