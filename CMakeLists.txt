cmake_minimum_required(VERSION 3.16)
project(SortingVisualizer)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
file(COPY resources DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

set(SFML_DIR "D:/University/MSA_Courses/Projects/Data Structure/SFML-2.6.1/lib/cmake/SFML")

find_package(SFML 2.6 REQUIRED COMPONENTS graphics window system audio)

add_executable(SortingVisualizer main.cpp
        include/ArrayManager.h
        src/ArrayManager.cpp
        include/Sorter.h
        src/Sorter.cpp
        include/Visualizer.h
        src/Visualizer.cpp
        include/Button.h
        src/Button.cpp
        include/UIManager.h
        src/UIManager.cpp
        include/Controller.h
        src/Controller.cpp
)

target_link_libraries(SortingVisualizer
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)