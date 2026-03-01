#include <stdio.h>
#include "grid.h"

Node grid[MAX][MAX];

void initializeGrid(int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].cost = 1;        // Default cost
            grid[i][j].isObstacle = 0;  // No obstacle
            grid[i][j].visited = 0;
            grid[i][j].parent = NULL;
        }
    }
}

void displayGrid(int rows, int cols, int startX, int startY, int goalX, int goalY) {
    printf("\nGRID DISPLAY:\n\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {

            if(i == startX && j == startY)
                printf(" S ");
            else if(i == goalX && j == goalY)
                printf(" G ");
            else if(grid[i][j].isObstacle)
                printf(" X ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}