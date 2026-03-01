#ifndef GRID_H
#define GRID_H

#define MAX 20

typedef struct Node {
    int x, y;            // Position
    int cost;            // Terrain cost
    int isObstacle;      // 1 if blocked
    int visited;         
    struct Node* parent; 
} Node;

extern Node grid[MAX][MAX];

void initializeGrid(int rows, int cols);
void displayGrid(int rows, int cols, int startX, int startY, int goalX, int goalY);

#endif