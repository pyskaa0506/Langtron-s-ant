#include "ant_simulation.h"
#include <Windows.h>
#include <stdio.h>

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



void simulate_ant(char **board, int m, int n, int iterations, int ant_position_x, int ant_position_y, char ant_direction)
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

        //print the board including the ant
        for (int i = 0; i < m; i++) {
            printf("\n");
            for (int j = 0; j < n; ++j) {
                if (i == ant.x && j == ant.y) {
                    printf("%c ", ant.direction);
                }
                else {
                    printf("%d ", board[i][j]);
                }
            }
        }
        printf("\n");
        printf("\n");

        move_ant(&ant, board, m, n);

        // sleep depending on the OS
        #ifdef _WIN32
        Sleep(1000);
        #else
        sleep(1);
        #endif

        // clear the screen
        printf("\033[H\033[J");
        fflush(stdout);
    }
}