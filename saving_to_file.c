#include "saving_to_file.h"
#include <stdio.h>
#include <string.h>

//int save_board(char **board, int iteration, char name[1000], int ant_x, int ant_y, char ant_direction, int m, int n){
//    //create file and save to file
//    //first line: ant_x, ant_y, ant_direction, m, n
//    //every other line: board
//
//    //create filename
//    char filename[1000];
//    sprintf(filename, "%s_%d.txt", name, iteration);
//
//    //create file
//    FILE *file;
//    file = fopen(filename, "w");
//    if (file == NULL) {
//        perror("Error opening file");
//        return -1;
//    }
//}