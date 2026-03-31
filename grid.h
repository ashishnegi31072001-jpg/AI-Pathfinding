#ifndef GRID_H
#define GRID_H

#define MAX 50

void initializeGrid(char grid[MAX][MAX], int rows, int cols);
void printGrid(char grid[MAX][MAX], int rows, int cols);
void addObstacles(char grid[MAX][MAX], int obstacles, int sx, int sy, int gx, int gy, int rows, int cols);
#endif