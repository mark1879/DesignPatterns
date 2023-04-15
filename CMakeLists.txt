cmake_minimum_required(VERSION 3.1)

project(DesignPatterns)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(Builder/)
add_subdirectory(Singleton/)
add_subdirectory(Factory/)
add_subdirectory(Proxy/)