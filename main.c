#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "board.h"
#include "display.h"
#include "ant_simulation.h"


int main(int argc, char *argv[])
{
    int m, n, iterations, ant_position_x, ant_position_y;
    char name[1000];
    char ant_direction;
    float obstacle_percentage; 
    char map_filename[1000];
    char initial_direction[10];

    input_arguments(argc, argv, &m, &n, &iterations, name, initial_direction, 
    &obstacle_percentage, map_filename, sizeof(map_filename), sizeof(initial_direction));

    //board inicialization
    char** board = create_board(m, n);
    load_board(board, m, n, map_filename, &ant_position_x, &ant_position_y, &ant_direction);
    black_spaces(board, m, n, obstacle_percentage);

    simulate_ant(board, m, n, iterations, ant_position_x, ant_position_y, ant_direction);

    free_board(board, m);
   
    return 0;
}