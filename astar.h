#ifndef ASTAR_H
#define ASTAR_H

#define MAX 50

int astar(char grid[MAX][MAX], int rows, int cols,
          int sx, int sy, int gx, int gy,
          int type, double *timeTaken);

#endif