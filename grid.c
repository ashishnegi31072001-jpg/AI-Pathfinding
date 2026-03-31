#include <stdio.h>
#include "grid.h"

void initializeGrid(char grid[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            grid[i][j] = '.';
        }
    }
}

void printGrid(char grid[MAX][MAX], int rows, int cols) {
    printf("\nGrid:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void addObstacles(char grid[MAX][MAX], int obstacles, int sx, int sy, int gx, int gy, int rows, int cols) {
    for(int i = 0; i < obstacles; i++) {
        int x, y;

        printf("Enter obstacle position (row col): ");
        if(scanf("%d %d", &x, &y) != 2) {
            printf("Invalid input! Try again.\n");
            i--;
            while(getchar() != '\n');
            continue;
        }

        if(x < 0 || x >= rows || y < 0 || y >= cols) {
            printf("Out of bounds! Try again.\n");
            i--;
            continue;
        }

        if(grid[x][y] == 'S' || grid[x][y] == 'G') {
            printf("Cannot place on S or G!\n");
            i--;
            continue;
        }

        if(grid[x][y] == 'X') {
            printf("Obstacle already exists! Try again.\n");
            i--;
            continue;
        }

        grid[x][y] = 'X';
    }

}