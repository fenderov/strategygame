cmake_minimum_required(VERSION 3.5)

project(client LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Network REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package (GTest REQUIRED)
find_package (Threads REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(Client)
include_directories(include)

macro(copy_directory _src _dst)
    execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory ${_src} ${_dst}
        RESULT_VARIABLE _res
        OUTPUT_VARIABLE _out
        ERROR_VARIABLE  _err
    )
    if(_err)
        message(FATAL_ERROR "ERROR ---> could not be copied: ${_err}")
    endif()
endmacro()

copy_directory(${CMAKE_SOURCE_DIR}/images ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/images)

add_subdirectory(source)

add_library(clientmainlib
    client.cpp
    client.h
    client.ui
    network.cpp
    network.h
    network.ui
)

target_link_libraries(clientmainlib Qt5::Widgets Qt5::Network source)

add_executable (CTest ${PROJECT_SOURCE_DIR}/main_test.cpp main_test.h)
target_link_libraries (CTest ${GTEST_LIBRARIES} Threads::Threads Qt5::Widgets clientmainlib)

enable_testing()
add_test(Ctest "./CTest")

add_executable(client
    main.cpp
)

target_link_libraries(client PRIVATE clientmainlib Qt5::Widgets Qt5::Network)

