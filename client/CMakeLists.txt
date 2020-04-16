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
find_package (GTest REQUIRED)
find_package (Threads REQUIRED)

set(CMAKE_INSTALL_RPATH build/lib)

project(Client)
include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Client_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${Client_SOURCE_DIR}/lib)

add_subdirectory(source)

add_library(clientmainlib
    client.cpp
    client.h
    client.ui
)

target_link_libraries(clientmainlib Qt5::Widgets source)

add_executable (CTest ${PROJECT_SOURCE_DIR}/main_test.cpp main_test.h)
target_link_libraries (CTest ${GTEST_LIBRARIES} Threads::Threads Qt5::Widgets clientmainlib)

enable_testing()
add_test(Ctest "./CTest")

add_executable(client
    main.cpp
)

target_link_libraries(client PRIVATE clientmainlib Qt5::Widgets)

