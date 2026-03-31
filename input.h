#ifndef INPUT_H
#define INPUT_H

#define MAX 50

void getGridSize(int *rows, int *cols);
void getStartGoal(int *sx, int *sy, int *gx, int *gy);
int getObstacles();
int getWeightedChoice();

#endif