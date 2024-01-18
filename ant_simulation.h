#ifndef LANGTRON_S_ANT_ANT_SIMULATION_H
#define LANGTRON_S_ANT_ANT_SIMULATION_H

typedef struct ant {
    int x;
    int y;
    char direction;
} ant;

void simulate_ant(char **board, int m, int n, int iterations, int ant_position_x, int ant_position_y, char ant_direction, char name[1000]);

#endif //LANGTRON_S_ANT_ANT_SIMULATION_H
