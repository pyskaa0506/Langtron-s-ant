#ifndef BOARD_H
#define BOARD_H

char** create_board(int m, int n);

void free_board(char** board, int m);

int load_board(const char *filename, int *ant_x, int *ant_y, char *ant_direction, int *m, int *n, char ***board);

void black_spaces(char** board, int m, int n, float obstacle_percentage);

#endif 
