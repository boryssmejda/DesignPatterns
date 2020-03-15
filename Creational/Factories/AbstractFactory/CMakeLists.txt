cmake_minimum_required(VERSION 3.6)
project(AbstractEquipmentFactory)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -std=c++17")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -std=c++17")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message("${CMAKE_CXX_FLAGS}")


set(SOURCE_FILES
    main.cpp
	AbstractFactory.hpp
	AbstractFactory.cpp
    GermanEquipment.hpp
    GermanEquipment.cpp
    AmericanEquipment.hpp
    AmericanEquipment.cpp
	BritishEquipment.cpp
	BritishEquipment.hpp
    )
add_executable(${PROJECT_NAME} ${SOURCE_FILES})