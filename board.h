#ifndef BOARD_H
#define BOARD_H

char** create_board(int m, int n);

void free_board(char** board, int m);

void display_board_n(char** board, int m, int n);

void load_board(char** board, int m, int n, char* map_filename, 
int* ant_position_x, int* ant_position_y, char* ant_direction);

void black_spaces(char** board, int m, int n, float obstacle_percentage);

#endif 
