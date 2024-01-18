cmake_minimum_required(VERSION 3.26)
project(Langtron_s_ant C)

set(CMAKE_C_STANDARD 11)

add_executable(Langtron_s_ant
        main.c
        board.c
        input.c
        display.c
        ant_simulation.c
        ant_simulation.h
        saving_to_file.c
        saving_to_file.h)
