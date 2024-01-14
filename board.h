#ifndef BOARD_H
#define BOARD_H

#define LINE_VERTICAL L"│"
#define LINE_HORIZONTAL L"─"
#define LINE_DOWN_RIGHT L"┌"
#define LINE_DOWN_LEFT L"┐"
#define LINE_UP_RIGHT L"└"
#define LINE_UP_LEFT L"┘"
#define SQUARE_WHITE L" "
#define SQUARE_BLACK L"█"
#define ARROW_NORTH_WHITE L"△"
#define ARROW_NORTH_BLACK L"▲"
#define ARROW_EAST_WHITE L"▷"
#define ARROW_EAST_BLACK L"▶"
#define ARROW_SOUTH_WHITE L"▽"
#define ARROW_SOUTH_BLACK L"▼"
#define ARROW_WEST_WHITE L"◁"
#define ARROW_WEST_BLACK L"◀"

char** create_board(int m, int n);

void load_board(char **board, int m, int n, char *map_filename, int *ant_position_x, 
int *ant_position_y, char *ant_direction);

void black_spaces(char **board, int m, int n, float obstacle_percentage);

void free_board(char **board, int m);


#endif 
