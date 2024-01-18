#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "display.h"


void display_board(char **board, int m, int n) 
{
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (board[i][j] == 0) 
            {
                printf(" ");
            } 
            else 
            {
                printf("█");
            }
        }
        printf("\n");
    }
}
