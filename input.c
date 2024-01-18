#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "input.h"

void input_arguments(int argc, char *argv[], int *m, int *n, int *iterations, 
char *name, char *initial_direction, float *obstacle_percentage,
char *map_filename, size_t map_filename_size, size_t initial_direction_size)
{
    int option; //przechowywa aktualną opcję przetwarz. przez getopt

    /*Tworzymy statyczną tablicę z info o opcjach dostęp dla programu
    1 pole - nazwa opcji
    2 pole - flaga o tym że argument jest wymagany
    3 - wskaźnik na zmienną
    4 - krótka opcja (znak jednoliterowy)
    */
    static struct option long_option[] = 
    {
        {"obstacle", required_argument, 0, 'o'},
        {"file", required_argument, 0,'f'},  
        {0, 0, 0,0}
    };
    
    *obstacle_percentage = 0.0;
    map_filename[0] = '\0';
    *iterations = 0;  

    while ((option = getopt_long(argc, argv, "o:f:", long_option, NULL)) != -1)
    {
        switch (option)
        {
            case 'o':
                *obstacle_percentage = atof(optarg);
                break;
            case 'f':
                snprintf(map_filename, map_filename_size,"%s", optarg);
                break;
            case '?':
                printf("Nieznana opcja: %c\n", optopt);
                exit(EXIT_FAILURE);
            default:
                break;
        }
    }

    //jeżeli plik z mapą został podany - nie wymagamy reszty argumentów
    if (map_filename[0] != '\0') 
    {
        if (argc - optind >= 5)
        {
            *n = atoi(argv[optind]);
            *m = atoi(argv[optind + 1]);
            *iterations = atoi(argv[optind + 2]);
            snprintf(name, sizeof(name), "%s", argv[optind + 3]);
            snprintf(initial_direction, initial_direction_size, "%s", argv[optind + 4]);
            if (initial_direction[0] == '\0') {
                snprintf(initial_direction, initial_direction_size, "N");
            }
            if (initial_direction[0] != 'N' && initial_direction[0] != 'E' && initial_direction[0] != 'S' && initial_direction[0] != 'W')
            {
                printf("Niepoprawny lub niepodany kierunek poczatkowy mrowki. Dostepne opcje: N, E, S, W\n");
                exit(EXIT_FAILURE);
            }
        }
        return;
    }

    // Jeżeli plik nie został podany, wymagamy pozostałych argumentów
    if (argc - optind < 5)
    {
        printf("Podano za malo argumentow. Program musi byc wywolany z argumentami: \n <n> <m> <iterations> <file_name_prefix> <initial_direction> [optional: -o <set_procent_black_squares> -f <map_filename>]\n");
        exit(EXIT_FAILURE);
    }

    *n = atoi(argv[optind]);
    *m = atoi(argv[optind + 1]);
    *iterations = atoi(argv[optind + 2]);
    snprintf(name, sizeof(name), "%s", argv[optind + 3]);
    snprintf(initial_direction, initial_direction_size, "%s", argv[optind + 4]);
    if (initial_direction[0] == '\0') {
        snprintf(initial_direction, initial_direction_size, "N");
    }
    if (initial_direction[0] != 'N' && initial_direction[0] != 'E' && initial_direction[0] != 'S' && initial_direction[0] != 'W')
    {
        printf("Niepoprawny lub niepodany kierunek poczatkowy mrowki. Dostepne opcje: N, E, S, W\n");
        exit(EXIT_FAILURE);
    }
}