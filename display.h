#ifndef DISPLAY_H
#define DISPLAY_H

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

void display_board(char **board, int m, int n);
void display_board_with_ant_utf(char **board, int m, int n, int ant_position_x, int ant_position_y, char ant_direction);
void display_board_utf(char **board, int m, int n);
void display_board_with_ant(char **board, int m, int n, int ant_position_x, int ant_position_y, char ant_direction);

#endif 
