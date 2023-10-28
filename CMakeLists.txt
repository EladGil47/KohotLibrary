CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
project(KohotLibrary VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

file(GLOB PROJECT_SOURCES
    src/*.cpp
    include/*.hpp
    include/nlohmann/*.hpp
)

add_library(KOHOT_LIB  ${PROJECT_SOURCES})

message("Found library:" ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(KOHOT_LIB PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)