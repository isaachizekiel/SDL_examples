cmake_minimum_required(VERSION 3.16)
project(SDL_examples C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(SDL_init SDL_init.c)
target_link_libraries(SDL_init ${SDL2_LIBRARIES})

add_executable(SDL_init_video_display SDL_init_video_display.c)
target_link_libraries(SDL_init_video_display ${SDL2_LIBRARIES})

add_executable(SDL_setup_display SDL_setup_display.c)
target_link_libraries(SDL_setup_display ${SDL2_LIBRARIES})

