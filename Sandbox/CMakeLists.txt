# Sandbox/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(Sandbox)

# Sandbox source files
set(SOURCE_FILES
    src/application.cpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link with the Engine
target_link_libraries(${PROJECT_NAME} PRIVATE Engine)