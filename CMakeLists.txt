cmake_minimum_required(VERSION 3.20)
project(GameEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add external dependencies directory
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/external")

# Add Engine and Sandbox projects
add_subdirectory(Engine)
add_subdirectory(Sandbox)