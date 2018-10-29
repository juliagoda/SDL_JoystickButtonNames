cmake_minimum_required(VERSION 3.6)
project(SDL_joystickbuttonnames_examples)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ECM_MODULE_PATH} "${CMAKE_ROOT}/Modules")

find_package(SDL2 REQUIRED)

if(NOT SDL2_FOUND)
  find_package(SDL REQUIRED)
  if(NOT SDL_FOUND)
    message(FATAL_ERROR "You need to install library names sdl2")
  else()
    include_directories(.. ${SDL_INCLUDE_DIR})
    link_directories(${SDL_LIBRARY_DIR})
  endif()
else()
    include_directories(.. ${SDL2_INCLUDE_DIRS})
    link_directories(${SDL2_LIBRARY_DIRS})
endif()


if("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
  add_definitions(-std=c99)
elseif(MSVC)
else()
  add_definitions(-std=gnu99)
endif()


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/.. ${CMAKE_CURRENT_BINARY_DIR}/lib)

# libSDLMain comes with libSDL if needed on certain platforms
if(NOT SDLMAIN_LIBRARY)
  set(SDLMAIN_LIBRARY "")
endif()

if (SDL2_FOUND)
    add_executable(find_all_joy_buttons find_all_joy_buttons.c)
    target_link_libraries(find_all_joy_buttons SDL_joystickbuttonnames ${SDL2_LIBRARIES})

    add_executable(minimal minimal.c)
    target_link_libraries(minimal SDL_joystickbuttonnames ${SDL2_LIBRARIES})
    
    add_executable(checkInfo check_info.c)
    target_link_libraries(checkInfo SDL_joystickbuttonnames ${SDL2_LIBRARIES})
    
    add_executable(minimalWithoutRGB minimal_without_rgb.c)
    target_link_libraries(minimalWithoutRGB SDL_joystickbuttonnames ${SDL2_LIBRARIES})
elseif(SDL_FOUND)
    add_executable(find_all_joy_buttons find_all_joy_buttons.c)
    target_link_libraries(find_all_joy_buttons SDL_joystickbuttonnames ${SDL_LIBRARY})

    add_executable(minimal minimal.c)
    target_link_libraries(minimal SDL_joystickbuttonnames ${SDL_LIBRARY})
    
    add_executable(checkInfo check_info.c)
    target_link_libraries(checkInfo SDL_joystickbuttonnames ${SDL_LIBRARY})
    
    add_executable(minimalWithoutRGB minimal_without_rgb.c)
    target_link_libraries(minimalWithoutRGB SDL_joystickbuttonnames ${SDL_LIBRARY})
endif()
