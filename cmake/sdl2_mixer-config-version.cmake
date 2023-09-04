# SDL2_mixer CMake version configuration file:
# This file is meant to be placed in a cmake subfolder of SDL2_mixer-devel-2.x.y-mingw

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(sdl2_mixer_config_path "${CMAKE_CURRENT_LIST_DIR}/../sdl_mixer/lib/cmake/SDL2_mixer/sdl2_mixer-config-version.cmake")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(sdl2_mixer_config_path "${CMAKE_CURRENT_LIST_DIR}/../sdl_mixer/lib/cmake/SDL2_mixer/sdl2_mixer-config-version.cmake")
else("${CMAKE_SIZEOF_VOID_P}" STREQUAL "")
    set(PACKAGE_VERSION_UNSUITABLE TRUE)
    return()
endif()

if(NOT EXISTS "${sdl2_mixer_config_path}")
    message(WARNING "${sdl2_mixer_config_path} does not exist: MinGW development package is corrupted")
    set(PACKAGE_VERSION_UNSUITABLE TRUE)
    return()
endif()

include("${sdl2_mixer_config_path}")