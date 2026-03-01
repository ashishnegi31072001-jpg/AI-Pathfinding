#include <stdio.h>
#include "grid.h"
#include "input.h"

int main() {

    int rows, cols;
    int startX, startY, goalX, goalY;
    int numObstacles;

    printf("Enter number of rows (max 20): ");
    scanf("%d", &rows);

    printf("Enter number of columns (max 20): ");
    scanf("%d", &cols);

    if(rows > MAX || cols > MAX) {
        printf("Grid size exceeds limit!\n");
        return 1;
    }

    initializeGrid(rows, cols);

    printf("Enter Start Position (x y): ");
    scanf("%d %d", &startX, &startY);

    printf("Enter Goal Position (x y): ");
    scanf("%d %d", &goalX, &goalY);

    printf("Enter number of obstacles: ");
    scanf("%d", &numObstacles);

    for(int i = 0; i < numObstacles; i++) {
        int x, y;
        printf("Enter obstacle %d position (x y): ", i + 1);
        scanf("%d %d", &x, &y);
        placeObstacle(x, y);
    }

    displayGrid(rows, cols, startX, startY, goalX, goalY);

    return 0;
}