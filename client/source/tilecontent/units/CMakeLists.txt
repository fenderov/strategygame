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

add_library(units SHARED
    unit.cpp
    unit.h
    unitlist.cpp
    unitlist.h
    unitfactory.cpp
    unitfactory.h
    army.cpp
    army.h
)

target_link_libraries(units Qt5::Widgets)
install(TARGETS units DESTINATION ${PROJECT_SOURCE_DIR}/build/lib)

