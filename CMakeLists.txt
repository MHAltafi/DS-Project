project(tamrin1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
	src/main.cpp
	src/Graph.cpp
)

cmake_minimum_required(VERSION 3.0)

include_directories(include/)

add_executable(app ${SOURCES})