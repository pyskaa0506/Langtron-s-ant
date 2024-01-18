#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "board.h"
#include "display.h"

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

    printf("m: %d\n", m);
    printf("n: %d\n", n);
    printf("iterations: %d\n", iterations);
    printf("name: %s\n", name);
    printf("initial_direction: %s\n", initial_direction);
    printf("obstacle_percentage: %f\n", obstacle_percentage);
    printf("map_filename: %s\n", map_filename);

    char** board = create_board(m, n);
    load_board(board, m, n, map_filename, &ant_position_x, &ant_position_y, &ant_direction);
    black_spaces(board, m, n, obstacle_percentage);

    printf("Initial Board:\n");
    display_board_n(board, m, n);
    printf("--------------------\n");
    display_board(board, m, n);

    /* Tutaj można umieścić kod symulacji mrówki Langtona
    for () 
    move_ant 
    simulation 
    save_result */

    free_board(board, m);
   
    return 0;
}