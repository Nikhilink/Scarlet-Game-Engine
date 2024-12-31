# Engine/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(Engine)

# Enable FetchContent
include(FetchContent)

# Fetch GLFW
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.8 # Specify the version you want
    SOURCE_DIR ${CMAKE_BINARY_DIR}/_deps/glfw-src
    BINARY_DIR ${CMAKE_BINARY_DIR}/_deps/glfw-build
)
FetchContent_MakeAvailable(glfw)

# Fetch GLAD
FetchContent_Declare(
    GLAD
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG v0.1.36 # Specify the version you want
    SOURCE_DIR ${CMAKE_BINARY_DIR}/_deps/glad-src
    BINARY_DIR ${CMAKE_BINARY_DIR}/_deps/glad-build
)

FetchContent_MakeAvailable(glad)

# Fetch GML
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 0.9.9.8
    SOURCE_DIR ${CMAKE_BINARY_DIR}/_deps/glm-src
)

FetchContent_MakeAvailable(glm)

# Engine source files
set(SOURCE_FILES
    src/window.cpp
    src/input/input.cpp
    src/input/keyboard.cpp
    src/input/mouse.cpp
    src/input/gamepad.cpp
    src/input/input_manager.cpp
    src/input/input_mappings.cpp
    src/renderer.cpp
    src/shader.cpp

    include/window.h
    include/input/input.h
    include/input/keyboard.h
    include/input/mouse.h
    include/input/gamepad.h
    include/input/input_manager.h
    include/input/input_mapping.h
    include/renderer.h
    include/shader.h

    
)

# Include directories
include_directories(
    include
    ${GLFW_INCLUDE_DIRS}
    ${GLAD_INCLUDE_DIRS}
)

# Add library
add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

find_package(OpenGL REQUIRED)

add_library(GLAD STATIC
    ${GLAD_BINARY_DIR}/src/glad.c
)

target_include_directories(Engine PUBLIC ${GLAD_SOURCE_DIR}/include include ${glfw_SOURCE_DIR}/include ${glm_SOURCE_DIR})

# Link dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE glfw OpenGL::GL GLAD)