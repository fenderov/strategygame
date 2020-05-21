cmake_minimum_required(VERSION 3.5)

project(client LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(units SHARED
    unit.cpp
    unit.h
    unitlist.cpp
    unitlist.h
    unitfactory.cpp
    unitfactory.h
    army.cpp
    army.h
    object.cpp
    object.h
    action.cpp
    action.h
)

target_link_libraries(units Qt5::Widgets Qt5::Network)
install(TARGETS units DESTINATION ${PROJECT_SOURCE_DIR}/build/lib)

