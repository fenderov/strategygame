cmake_minimum_required(VERSION 3.5)

project(client LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(client SHARED
    main.cpp
    client.cpp
    client.h
    client.ui
  )
else()
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
  )
endif()

target_link_libraries(client PRIVATE Qt5::Widgets)
