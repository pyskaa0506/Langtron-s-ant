#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "board.h"

int main(int argc, char *argv[])
{
    int m, n, iterations, ant_position_x, ant_position_y;
    char name[1000];
    char ant_direction;
    float obstacle_percentage; 
    char map_filename[1000];

    input_arguments(argc, argv, &m, &n, &iterations, name, &ant_direction, &obstacle_percentage, map_filename);

    char** board = create_board(m,n);
    load_board(board, m,n, NULL, &ant_position_x, &ant_position_y, &ant_direction);

    //initialize_ant

    /* for () 
    move_ant 
    simulation 
    save_result */

    free_board(board, m);

    return 0;
}