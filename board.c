#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "board.h"

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

void load_board(char** board, int m, int n, char* map_filename, int* ant_position_x, 
int* ant_position_y, char* ant_direction) 
{
    FILE* file;
    char line[1000];

     if (map_filename != NULL && map_filename[0] != '\0')  
     {
        file = fopen(map_filename, "r");

        if (file==NULL) 
        {
            printf("Nie udalo sie otworzyc pliku %s\n", map_filename);
            exit(EXIT_FAILURE);

        }

        for (int i = 0; i < m; i++) 
        {
            if (fgets(line, sizeof(line), file) != NULL) 
            {
                for (int j = 0; j < n; j++) 
                {
                    if (line[j] == 0)
                    {
                        board[i][j] = 0; //biała kratka
                    } 
                    else if (line[j] == 1)
                    {
                        board[i][j] = 1; //czarna kratka
                    }
                }
            }
        }
        fclose(file);

    } 
    else //jeżeli plik nie jest podany - to plansza z losowymi wartośćiami
    {
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                board[i][j] = rand() % 2; //losowo ustaw 0 lub 1
            }
        }
    }

    // Początkowa pozycja mrówki - zakładam, że znajduje się ona w środku planszy
    // Ustaw pozycję mrówki na środku planszy (gdy wymiar jest nieparzysty)
        if (n % 2 != 0) 
        {
            *ant_position_y = (n - 1) / 2;
        } 
        else 
        {
            *ant_position_y = n / 2;
        }

        if (m % 2 != 0) 
        {
            *ant_position_x = (m - 1) / 2;
        } 
        else 
        {
            *ant_position_x = m / 2;
        }

        *ant_direction = 'N'; // Zakładam, że początkowy kierunek to północ (North)
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

// Funkcja dla wyświetlenia planszy w postaci 0 i 1
void display_board_n(char** board, int m, int n) 
{
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
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
