cmake_minimum_required(VERSION 3.25)
project(simulator_race)

set(CMAKE_CXX_STANDARD 17)

add_library(all_transport SHARED din_library_for_racing/ground/camel.cpp din_library_for_racing/ground/camel.h din_library_for_racing/ground/camel_fast.cpp din_library_for_racing/ground/camel_fast.h din_library_for_racing/ground/centaur.cpp din_library_for_racing/ground/centaur.h din_library_for_racing/ground/all_terrain_boots.cpp din_library_for_racing/ground/all_terrain_boots.h din_library_for_racing/air/Magic_carpet.cpp din_library_for_racing/air/Magic_carpet.h din_library_for_racing/air/Eagle.cpp din_library_for_racing/air/Eagle.h din_library_for_racing/air/Broom.cpp din_library_for_racing/air/Broom.h)
add_executable(simulator_race main.cpp)
target_link_libraries(simulator_race all_transport)

