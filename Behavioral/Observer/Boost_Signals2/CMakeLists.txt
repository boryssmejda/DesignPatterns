cmake_minimum_required(VERSION 3.9)

project(BoostSignals VERSION 1.0.0 DESCRIPTION "Observer DP using boost signals2 module")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Detect compiler and set proper flags
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Wshadow")
endif()

find_package(Boost 1.72 REQUIRED)
set(SOURCE_FILES
    main.cpp
    ISubject.hpp
    IObserver.hpp
    Journalism.cpp
    Journalism.hpp    
    )
add_executable(${PROJECT_NAME} ${SOURCE_FILES})