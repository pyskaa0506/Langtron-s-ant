#include "ant_simulation.h"
#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h> 
#include "display.h"
#ifdef _WIN32
#include <windows.h>
#endif
#include "saving_to_file.h"


void chng_dir_r(ant *ant) {

    if (ant->direction == '^') {
        ant->direction = '>';
    } else if (ant->direction == '>') {
        ant->direction = 'V';
    } else if (ant->direction == 'V') {
        ant->direction = '<';
    } else if (ant->direction == '<') {
        ant->direction = '^';
    }
}


void chng_dir_l(ant *ant) {

    if (ant->direction == '^') {
        ant->direction = '<';
    } else if (ant->direction == '>') {
        ant->direction = '^';
    } else if (ant->direction == 'V') {
        ant->direction = '>';
    } else if (ant->direction == '<') {
        ant->direction = 'V';
    }
}


int move_ant(ant *ant, char **board, int m, int n) {

    if (board[ant->x][ant->y] == 0) {
        board[ant->x][ant->y] = 1;
        chng_dir_r(ant);
    } else if (board[ant->x][ant->y] == 1) {
        board[ant->x][ant->y] = 0;
        chng_dir_l(ant);
    }

    if (ant->direction == '^') {
        if (ant->x == 0) {
            ant->x = m - 1;
        } else {
            ant->x--;
        }

    } else if (ant->direction == '>') {
        if (ant->y == n - 1) {
            ant->y = 0;
        } else {
            ant->y++;
        }
    } else if (ant->direction == 'V') {
        if (ant->x == m - 1) {
            ant->x = 0;
        } else {
            ant->x++;
        }
    } else if (ant->direction == '<') {
        if (ant->y == 0) {
            ant->y = n - 1;
        } else {
            ant->y--;
        }
    }

    return 0;
}


void sleepf(int time){
    // sleep depending on the OS
    #ifdef _WIN32
        #include <windows.h>
        Sleep(time*1000);
    #else
        sleep(time);
    #endif
}


void simulate_ant(char **board, int m, int n, int iterations, int ant_position_x, int ant_position_y, char ant_direction, char name[1000])
{
    //initialize the ant
    ant ant;
    ant.x = ant_position_x;
    ant.y = ant_position_y;

    if (ant_direction == 'N')
        ant.direction = '^';
    else if (ant_direction == 'E')
        ant.direction = '>';
    else if (ant_direction == 'S')
        ant.direction = 'V';
    else if (ant_direction == 'W')
        ant.direction = '<';

    for (int i = 0; i < iterations; i++) {

        save_board(board, i + 1, name, ant.x, ant.y, ant.direction, m, n);

        display_board_with_ant_utf(board, m, n, ant.x, ant.y, ant.direction);

        move_ant(&ant, board, m, n);

        sleepf(1); //sleep for 1 second

        // clear the screen
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
}