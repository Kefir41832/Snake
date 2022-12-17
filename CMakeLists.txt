cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
include(CTest)
enable_testing()

add_executable(main main.cpp Game.cpp Snake.cpp ncurses_wrapper.cpp)
target_link_libraries(main ncurses)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
