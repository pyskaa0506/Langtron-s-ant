#include "saving_to_file.h"
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
    #include <direct.h>
#else
    #include <sys/stat.h>
    #include <sys/types.h>
#endif

//create file and save to file
//first line: ant_x, ant_y, ant_direction, m, n
//every other line: board
int save_board(char **board, int iteration, char name[1000], int ant_x, int ant_y, char ant_direction, int m, int n){

    char direction;
    if (ant_direction == '^'){
        direction = 'N';
    } else if (ant_direction == '>'){
        direction = 'E';
    } else if (ant_direction == 'V'){
        direction = 'S';
    } else if (ant_direction == '<'){
        direction = 'W';
    }


    // Create the "maps" directory in the parent directory
#ifdef _WIN32
    _mkdir("../maps");
#else
    mkdir("../maps", 0777);
#endif

    //create filename
    char filename[1000];
    sprintf(filename, "../maps/%s_%d.txt", name, iteration);

    //create file
    FILE *file;
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    //first line
    fprintf(file, "%d %d %c %d %d\n", ant_x, ant_y, direction, m, n);

    //every other line
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fprintf(file, "%d ", board[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    return 0;
}