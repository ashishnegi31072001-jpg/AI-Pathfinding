#ifndef BFS_H
#define BFS_H

#define MAX 50

int bfs(char grid[MAX][MAX], int rows, int cols,
        int sx, int sy, int gx, int gy,
        double *timeTaken);

#endif