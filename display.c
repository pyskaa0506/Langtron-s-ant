#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>
#include "display.h"

void set_unicode_mode() {
#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
#endif
}

void display_board(char **board, int m, int n)
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
