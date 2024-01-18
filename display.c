#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <fcntl.h>
#include <locale.h>
#include "display.h"

void set_unicode_mode() {
#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
#else
    setlocale(LC_ALL, ""); // Ustaw konsolę do obsługi znaków Unicode
#endif
}

void display_board(char **board, int m, int n)
{
    //print the board
    for (int i = 0; i < m; i++) {
        printf("\n");
        for (int j = 0; j < n; ++j) {
            printf("%d ", board[i][j]);
        }
    }
    printf("\n");
    printf("\n");
}

void display_board_with_ant(char **board, int m, int n, int ant_position_x, int ant_position_y, char ant_direction)
{
    //print the board including the ant
    for (int i = 0; i < m; i++) {
        printf("\n");
        for (int j = 0; j < n; ++j) {
            if (i == ant_position_x && j == ant_position_y) {
                printf("%c ", ant_direction);
            }
            else {
                printf("%d ", board[i][j]);
            }
        }
    }
    printf("\n");
    printf("\n");
}

void display_board_utf(char **board, int m, int n)
{
    // Set the console to handle Unicode characters
    set_unicode_mode();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
            {
                wprintf(L"\u2591");
            }
            else
            {
                wprintf(L"\u2588");
            }
        }
        wprintf(L"\n");
    }
}

void display_board_with_ant_utf(char **board, int m, int n, int ant_position_x, int ant_position_y, char ant_direction){
    // Set the console to handle Unicode characters
    set_unicode_mode();

    //print the board including the ant in UTF-8
    for (int i = 0; i < m; i++) {
        wprintf(L"\n");
        for (int j = 0; j < n; ++j) {
            if (i == ant_position_x && j == ant_position_y) {
                if (ant_direction == '^') {
                    wprintf(L"▲ ");
                } else if (ant_direction == '>') {
                    wprintf(L"▶ ");
                } else if (ant_direction == 'V') {
                    wprintf(L"▼ ");
                } else if (ant_direction == '<') {
                    wprintf(L"◀ ");
                }
            }
            else {
                if (board[i][j] == 0) {
                    wprintf(L"░ ");
                } else {
                    wprintf(L"█ ");
                }
            }
        }
    }
    wprintf(L"\n");
    wprintf(L"\n");
}
