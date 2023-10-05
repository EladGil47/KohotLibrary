CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
project(KohotLibrary VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_library(KOHOT_LIB  
src/base_collection.cpp
src/group.cpp
src/groups_collection.cpp  
src/json_utils.cpp  
src/kohot.cpp  
src/player.cpp  
src/players_collection.cpp  
src/players_sorter.cpp  
src/team.cpp  
src/teams_creator.cpp  
src/utility_functions.cpp  
include/base_collection.hpp  
include/console_colors.hpp  
include/group.hpp  
include/groups_collection.hpp  
include/json_utils.hpp  
include/kohot.hpp  
include/player.hpp  
include/players_collection.hpp  
include/players_sorter.hpp  
include/team.hpp  
include/teams_creator.hpp  
include/utility_functions.hpp
)
message("Found library:" ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(KOHOT_LIB PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)