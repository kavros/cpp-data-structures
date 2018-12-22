cmake_minimum_required(VERSION 2.8)

project(dataStructures)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(SOURCE_FILES 
    ./src/list/examples/main.cpp 
    ./src/list/src/list.cpp 
    ./src/list/src/queue.cpp 
    ./src/list/src/stack.cpp
)

include_directories("${PROJECT_SOURCE_DIR}/src/list/include")
link_directories("${PROJECT_SOURCE_DIR}/src/list/include")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

