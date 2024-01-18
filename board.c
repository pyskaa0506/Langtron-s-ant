#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "board.h"
#include "ant_simulation.h"

//Dwówymiarowa tablicz m*n 
char** create_board(int m, int n) 
{
    char** board = (char**)malloc(m * sizeof(char*));
    for (int i = 0; i <m; i++) 
    {
        board[i] = (char*)malloc(n * sizeof(char));
    }

    return board;
}



//Dla wczytywania już gotowej mapy (jeżeli taka istnieje)

int load_board(const char *filename, int *ant_x, int *ant_y, char *ant_direction, int *m, int *n, char ***board) {

    char full_path[1000];
    sprintf(full_path, "../maps/%s", filename);

    FILE *file = fopen(full_path, "r");

    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read the first line
    fscanf(file, "%d %d %c %d %d\n", ant_x, ant_y, ant_direction, m, n);

    // Allocate memory for the board
    *board = (char **)malloc(*m * sizeof(char *));
    for (int i = 0; i < *m; i++) {
        (*board)[i] = (char *)malloc(*n * sizeof(char));
    }

    // Read the board content
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            fscanf(file, " %d", &(*board)[i][j]);
        }
    }

    fclose(file);
    return 0;
}



//Dla zwolnienia pamięci
void free_board(char** board, int m) 
{
    for (int i = 0; i<m;i++) 
    {
        free(board[i]);
    }
    free(board) ;
}


void black_spaces(char** board, int m, int n, float obstacle_percentage) 
{
    srand(time(NULL));

    int total_cells = m*n;
    int black_cells_to_generate = (int)(obstacle_percentage * total_cells/100);

    // Wypełnij planszę zerami
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j <n; j++) 
        {
            board[i][j] = 0;
        }
    }

    // Ustaw odpowiednią liczbę jednek
    for (int i = 0; i< black_cells_to_generate; i++) 
    {
        int x, y;
        do 
        {
            x = rand() % m;
            y = rand() % n;
        } 
        while (board[x][y] == 1);

        board[x][y] = 1;
    }
}
