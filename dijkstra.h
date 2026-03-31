#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define MAX 50

int dijkstra(char grid[MAX][MAX], int rows, int cols,
             int sx, int sy, int gx, int gy,
             double *timeTaken);

#endif