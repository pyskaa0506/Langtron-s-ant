#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

//moduł odpowiadający za  odczytywanie pametrów wejściowych
void input_arguments(int argc, char *argv[], int *m, int *n, int *iterations, 
char *name, char *initial_direction, float *obstacle_percentage, char *map_filename)
{
    //Po pierwsze, dodamy informacje dla użytkownika o prawidłowym użyciu programu, jeśli było ono nieprawidłowe
if (argc < 6)
    {
        printf("Program %s musi być wywołany razem z następną informacją <m> <n> <iterations> <name> <initial_direction> [optional_arguments}(nie są obowiązkowe)\n", argv[0]);
        exit(EXIT_FAILURE);

    }

    *m = atoi(argv[1]); //pobiera rozmiar planszy i przekształcamy na liczy całkowite
    *n = atoi(argv[2]);
    *iterations =atoi(argv[3]);
    //snprintf - zapisuje dane do określonego bufora, zapobiegając nadmiernemu zapisowi danych
    snprintf(name, sizeof(name), "%s", argv[4]);
    snprintf(initial_direction, sizeof(initial_direction), "%s", argv[5]);

    //opcjonalne parametry
    *obstacle_percentage=0.0;
    map_filename[0] = '\0';

    for (int i = 6; i < argc; i++)
    {
        if (strcmp(argv[i], "-o") == 0 && i+1 < argc)
        {
            *obstacle_percentage =atof(argv[i+1]);
            i++; //pomiń następny element 

        }
        else if (strcmp(argv[i], "-f") == 0 && i+1 < argc)
        {
            snprintf(map_filename, sizeof(map_filename), "%s", argv[i+ 1]);
            i++;

        }

        // tu możemy dodać info o innych dod parametrach

    }

}
