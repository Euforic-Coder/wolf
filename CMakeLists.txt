cmake_minimum_required(VERSION 3.5)

project(wolf LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(uforia)
add_executable(wolf main.cpp)
target_link_libraries(wolf uforia)

install(TARGETS wolf
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
