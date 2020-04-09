cmake_minimum_required(VERSION 3.5)

project(client LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package (Qt5Widgets)

#find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(client
    main.cpp
    client.cpp
    client.h
    client.ui
    source/game.cpp
    source/game.h
    source/map.cpp
    source/map.h
    source/tile.cpp
    source/tile.h
    source/player.cpp
    source/player.h
    source/land.cpp
    source/land.h
    source/unit.cpp
    source/unit.h
    source/unitlist.cpp
    source/unitlist.h
    source/building.cpp
    source/building.h
    source/buildinglist.cpp
    source/buildinglist.h
    source/unitfactory.cpp
    source/unitfactory.h
    source/fraction.cpp
    source/fraction.h
    source/army.cpp
    source/army.h
    source/actionfield.cpp
    source/actionfield.h
    source/actionbutton.cpp
    source/actionbutton.h
    source/buildingfactory.cpp
    source/buildingfactory.h
)

target_link_libraries(client PRIVATE Qt5::Widgets)
