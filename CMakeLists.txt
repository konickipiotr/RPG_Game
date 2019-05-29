cmake_minimum_required(VERSION 3.10.2)

project(RPG_Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -Wall")

include_directories(include)
include_directories(include/Characters)
include_directories(include/Items)
include_directories(include/Map)
include_directories(include/Place)
include_directories(include/Quests)

file(GLOB_RECURSE CLASSES "src/*.cpp")

set(SOURCESS ${CLASSES} "RPG.cpp")
add_executable(${PROJECT_NAME} ${SOURCESS})
