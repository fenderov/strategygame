cmake_minimum_required(VERSION 3.5)

project(client LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(units)

add_library(tilecontent SHARED
    land.cpp
    land.h
    building.cpp
    building.h
    buildinglist.cpp
    buildinglist.h
    buildingfactory.cpp
    buildingfactory.h
)

target_link_libraries(tilecontent Qt5::Widgets units)
install(TARGETS tilecontent DESTINATION ${PROJECT_SOURCE_DIR}/build/lib)

