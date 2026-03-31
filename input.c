#include <stdio.h>
#include "input.h"

void getGridSize(int *rows, int *cols) {
    printf("Enter rows and cols: ");
    scanf("%d %d", rows, cols);
}

void getStartGoal(int *sx, int *sy, int *gx, int *gy) {
    printf("Enter Start position (row col): ");
    scanf("%d %d", sx, sy);

    printf("Enter Goal position (row col): ");
    scanf("%d %d", gx, gy);
}

int getObstacles() {
    int obstacles;
    printf("Enter number of obstacles: ");
    scanf("%d", &obstacles);
    return obstacles;
}

int getWeightedChoice() {
    int choice;
    printf("\nEnter 0 for Unweighted Graph\n");
    printf("Enter 1 for Weighted Graph\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    return choice;
}