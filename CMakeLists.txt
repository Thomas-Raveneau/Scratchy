cmake_minimum_required(VERSION 3.20)
project(Scratchy C CXX)

# Specifying the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Downloading conan.cmake
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

# Setting the libraries directory
set (LIBS_DIR "Libs/")

# Setting the libraries sources
set(LIBS_SOURCES
        ${LIBS_DIR}/stb_image.cpp ${LIBS_DIR}/stb_image.h)

# Setting the source directory
set(SRC_DIR "Sources/")

# Setting the source files
set(SOURCES
        ${SRC_DIR}/main.cpp

        ${SRC_DIR}/Main/Viewport.cpp                    ${SRC_DIR}/Main/Viewport.h
        ${SRC_DIR}/Main/Window.cpp                      ${SRC_DIR}/Main/Window.h

        ${SRC_DIR}/Mesh/IMesh.h
        ${SRC_DIR}/Mesh/Mesh.cpp                        ${SRC_DIR}/Mesh/Mesh.h
        ${SRC_DIR}/Mesh/Shader.cpp                      ${SRC_DIR}/Mesh/Shader.h
        ${SRC_DIR}/Mesh/Texture.cpp                     ${SRC_DIR}/Mesh/Texture.h

        ${SRC_DIR}/Mesh/Primitives/Rect.cpp             ${SRC_DIR}/Mesh/Primitives/Rect.h
        ${SRC_DIR}/Mesh/Primitives/Cube.cpp             ${SRC_DIR}/Mesh/Primitives/Cube.h
        ${SRC_DIR}/Mesh/Primitives/Triangle.cpp         ${SRC_DIR}/Mesh/Primitives/Triangle.h

        ${SRC_DIR}/Utils/Color.cpp                      ${SRC_DIR}/Utils/Color.h
        ${SRC_DIR}/Utils/Angle.cpp                      ${SRC_DIR}/Utils/Angle.h
        ${SRC_DIR}/Utils/Vector2.cpp                    ${SRC_DIR}/Utils/Vector2.h
        ${SRC_DIR}/Utils/Position2.cpp                  ${SRC_DIR}/Utils/Position2.h
        ${SRC_DIR}/Utils/Position3.cpp                  ${SRC_DIR}/Utils/Position3.h)


# Adding the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${LIBS_SOURCES})

# Setting the include directories for preventing include with path
include_directories(${SRC_DIR} ${LIBS_DIR})

# Including conan.cmake
include(${CMAKE_BINARY_DIR}/conan.cmake)

# Installing project dependencies using conanfile.txt configuration
conan_cmake_run(CONANFILE conanfile.txt
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing)

# Including conan generated paths
include("${CMAKE_BINARY_DIR}/conan_paths.cmake")

# Finding OpenGL in the system using conan's paths
find_package(OpenGL REQUIRED)

# Finding GLFW in the system using conan's paths
find_package(glfw3 3.3 REQUIRED)

# Finding GLAD in the system using conan's paths
find_package(glad REQUIRED)

# Linking libraries to the project
target_link_libraries(${PROJECT_NAME} PUBLIC glfw OpenGL::GL glad::glad)
