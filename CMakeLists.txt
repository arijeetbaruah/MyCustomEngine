cmake_minimum_required(VERSION 3.14)

project(custom_engine)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/build)

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SRC_FILES
    ${CMAKE_SOURCE_DIR}/src/*.c
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE HEADER_FILES
    ${CMAKE_SOURCE_DIR}/include/*.h
    ${CMAKE_SOURCE_DIR}/include/*.hpp
)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/submodules/glfw)
include_directories(${CMAKE_SOURCE_DIR}/submodules/glfw/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/submodules/glm)
include_directories(${CMAKE_SOURCE_DIR}/submodules/glm)

add_executable(custom_engine ${HEADER_FILES} ${SRC_FILES})
install(TARGETS custom_engine DESTINATION bin)
target_link_libraries(custom_engine glfw opengl32 glm)
