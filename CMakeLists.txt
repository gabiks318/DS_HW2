cmake_minimum_required(VERSION 3.17)
project(DS_HW2)

set(CMAKE_CXX_STANDARD 11)

add_executable(DS_HW2 main.cpp submission_folder/CarAgenciesManager.cpp submission_folder/UnionFindAgency.cpp submission_folder/CarType.cpp submission_folder/CarSales.cpp library2.cpp)

add_subdirectory("./submission_folder")