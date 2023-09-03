cmake_minimum_required(VERSION 3.26)
project(push_swap C)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_C_STANDARD 11)
# Specify where to find packages. This is required if SDL2's CMake module is not globally available.
#list(APPEND CMAKE_MODULE_PATH "path_to_SDL2_cmake_module")

list(APPEND CMAKE_PREFIX_PATH "x86_64-w64-mingw32/lib/cmake/SDL2")
list(APPEND CMAKE_PREFIX_PATH "sdl_mixer/lib/cmake/SDL2_mixer")
list(APPEND CMAKE_PREFIX_PATH "cmake")
list(APPEND CMAKE_PREFIX_PATH "SDL2_ttf/lib/cmake/SDL2_ttf")
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(
        .
        ${SDL2_INCLUDE_DIRS}
        x86_64-w64-mingw32/include
        x86_64-w64-mingw32/include/SDL2
        sdl_mixer/include/SDL2
        SDL2_ttf/include/SDL2
)

add_executable(push_swap
        printers.c
        push_swap.c
        push_swap.h
        push_swap_utils.c
        movement.c
        sorter.c
)
target_link_libraries(push_swap ${SDL2_LIBRARIES})
target_link_libraries(push_swap ${SDL2_MIXER_LIBRARIES})
#target_link_libraries(push_swap ${SDL2_TTF_LIBRARIES})
target_link_libraries(${PROJECT_NAME} SDL2_ttf::SDL2_ttf)
