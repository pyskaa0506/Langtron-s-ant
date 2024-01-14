#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include "board.h"


//Dwówymiarowa tablicz m*n 
char** create_board(int m, int n)
{
    char** board = (char**)malloc(m*sizeof(char*));
    for (int i=0; i < m; ++i)
    {
        board[i] = (char*)malloc(n * sizeof(char));
        for (int j = 0; j < n; ++j) 
        {
            board[i][j] = *SQUARE_WHITE;
        }
    }
    return board;
}

//Dla wczytywania już gotowej mapy (jeżeli taka istnieje)
void load_board(char **board, int m, int n, char *map_filename, int *ant_position_x, 
int *ant_position_y, char *ant_direction)
{
    //jeżeli nie podano pliku - przyjmujemy domyślną planszę 
    if (map_filename == NULL) 
    {
        return;
    }

    FILE *file = fopen( map_filename, "r");
    if (file == NULL) {
        printf("Wystąpił bład. Nie mogę otworzyć tej planszy %s\n", map_filename);
        exit(EXIT_FAILURE );

    }

    for (int i =0; i < m; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            char current_char = fgetc(file);
            if (current_char != EOF && current_char != '\n') //przypisujemy odczytany znak do odpowiedniej komórki 
            {
                board[i][j] = current_char;
                //sprawdzenie pozycji mrówki
                if (current_char == *ARROW_NORTH_WHITE || current_char == *ARROW_NORTH_BLACK ||
                    current_char == *ARROW_EAST_WHITE || current_char == *ARROW_EAST_BLACK ||
                    current_char == *ARROW_SOUTH_WHITE || current_char == *ARROW_SOUTH_BLACK ||
                    current_char == *ARROW_WEST_WHITE || current_char == *ARROW_WEST_BLACK) {
                    
                    *ant_position_x=i;
                    *ant_position_y=j;
                    *ant_direction=current_char;
                }
            } 
            else 
            {
                board[i][j] = *SQUARE_WHITE; //jeżeli plik się skończyl - ustaw białą komurkę
            }
        }
    }
    fclose(file);

}

//Dla generowania czarnych pol na podstawie % zapełnienia
void black_spaces(char **board, int m, int n, float obstacle_percentage)
{
    //nie generujemy przeszkód, gdy wartość procentowa jest nieprawidłowa
    if (obstacle_percentage <= 0.0 || obstacle_percentage >= 100.0)
    {
        return;
    }

    int total_cells = m*n;
    int obstacle_cells=(int)(obstacle_percentage/100.0 * total_cells);

    //inicjuje generator liczb pseudolosowych na podstawie aktualnego czasu - różna dla każdego uruchamienia
    srand((unsigned int)time(NULL));

    for (int i =0; i < obstacle_cells; ++i)
    {
        int random_column = rand()%n;
        int random_row = rand()%m;

        if (board[random_row][random_column] != *SQUARE_BLACK) //sprawdzamy czy komórka nie jest już czarna
        {
            board[random_row][random_column] = *SQUARE_BLACK;
        }
        else 
        {
            --i; //jeżeli jest czarna, to powtarzamy proces losowania
        }
    }
}

//Dla zwolnienia pamięci
void free_board(char **board, int m)
{
    for (int i = 0; i <m; i++)
    {
        free(board[i]);
    }
    free(board);
}
