cmake_minimum_required(VERSION 3.6)
project(TankFactory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -std=c++17")

message("${CMAKE_CXX_FLAGS}")


set(SOURCE_FILES
    main.cpp
    Tank.hpp
    Tank.cpp
    TankFactory.hpp
    TankFactory.cpp
    )
add_executable(${PROJECT_NAME} ${SOURCE_FILES})