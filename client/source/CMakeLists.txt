cmake_minimum_required(VERSION 3.5)

project(client LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
add_subdirectory(tilecontent)

add_library(source SHARED
    game.cpp
    game.h
    map.cpp
    map.h
    tile.cpp
    tile.h
    player.cpp
    player.h
    fraction.cpp
    fraction.h
    database.cpp
    database.h
    actionfield.cpp
    actionfield.h
    button.cpp
    button.h
    widget.cpp
    widget.h
    basenetwork.cpp
    basenetwork.h
    networkpackage.cpp
    networkpackage.h
)

target_link_libraries(source Qt5::Widgets Qt5::Network tilecontent)

