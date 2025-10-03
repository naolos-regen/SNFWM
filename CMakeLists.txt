cmake_minimum_required(VERSION 4.1)
project(scfwm C)

find_package(X11 REQUIRED)

# Explicitly set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)


include_directories(${X11_INCLUDE_DIR})
include_directories(include)

add_executable(scfwm
        include/x11_helpers.h
        src/x11_helpers/x11_error_handler.c
        src/x11_helpers/x11_free.c
        src/x11_helpers/x11_init_display.c
        src/x11_helpers/x11_set_masks.c
        src/main.c)

target_link_libraries(scfwm ${X11_LIBRARIES})