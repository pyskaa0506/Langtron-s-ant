#include <stdio.h>
#include "input.h"
#include "board.h"
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

    char** board = create_board(m, n);

    //if the map file is provided, load the board from the file, otherwise generate a random board
    if (map_filename[0] != '\0')
    {
        if (load_board(map_filename, &ant_position_x, &ant_position_y, &ant_direction, &m, &n, &board) != 0) {
            fprintf(stderr, "Failed to read the file.\n");
            return 1; // Return an error code
        }
    }
    else
    {
        black_spaces(board, m, n, obstacle_percentage);
        ant_position_x = m / 2;
        ant_position_y = n / 2;
        ant_direction = initial_direction[0];
    }

    simulate_ant(board, m, n, iterations, ant_position_x, ant_position_y, ant_direction, name);

    free_board(board, m);
   
    return 0;
}