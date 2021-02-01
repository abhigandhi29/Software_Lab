cmake_minimum_required(VERSION 3.13)
project(LSM_system)

set (CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_CXX_STANDARD 17)  
set (CMAKE_CXX_FLAGS "-pthread")

set(src
    parser.cpp
    novel_parser.cpp
    play_parser.cpp
    file_watcher.cpp
    main.cpp
)

add_executable(LSM
${src}
)