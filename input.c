#include <stdio.h>
#include "grid.h"

void placeObstacle(int x, int y) {
    if(x >= 0 && x < MAX && y >= 0 && y < MAX) {
        grid[x][y].isObstacle = 1;
    }
}