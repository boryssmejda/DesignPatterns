cmake_minimum_required(VERSION 3.6)
project(ObserverPattern)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -std=c++17")

message("${CMAKE_CXX_FLAGS}")


set(SOURCE_FILES
    main.cpp
    ISubject.hpp
    IObserver.hpp
    Journalism.cpp
    Journalism.hpp    
    )
add_executable(${PROJECT_NAME} ${SOURCE_FILES})