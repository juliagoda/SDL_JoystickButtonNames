cmake_minimum_required(VERSION 3.6)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ECM_MODULE_PATH} "${CMAKE_ROOT}/Modules" "${CMAKE_CURRENT_SOURCE_DIR}/modules/")
find_package(SDL2 REQUIRED)

if(NOT SDL2_FOUND)
  find_package(SDL REQUIRED)
  if(NOT SDL_FOUND)
    message(FATAL_ERROR "You need to install library names sdl2")
  endif()  
endif()

if(SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIRS})
elseif(SDL_FOUND)
    include_directories(${SDL_INCLUDE_DIR})
endif()


file(READ gamecontrollerbuttondb.txt DB)
# Escape the newlines so it appears as multi line string in C
string(REPLACE "\n" "\\n\\\n" DB ${DB})
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/db.h.cmake ${CMAKE_CURRENT_SOURCE_DIR}/db.h)
set_source_files_properties(
  ${CMAKE_CURRENT_SOURCE_DIR}/db.h PROPERTIES GENERATED TRUE)

if(SDL2_FOUND)
    add_library(SDL_joystickbuttonnames STATIC
    SDL_joystickbuttonnames.c SDL_joystickbuttonnames.h)
    target_link_libraries(SDL_joystickbuttonnames ${SDL2_LIBRARIES})
elseif(SDL_FOUND)
    add_library(SDL_joystickbuttonnames STATIC
    SDL_joystickbuttonnames.c SDL_joystickbuttonnames.h)
    target_link_libraries(SDL_joystickbuttonnames ${SDL_LIBRARY})
endif()
