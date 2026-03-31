#include <stdio.h>
#include "grid.h"
#include "bfs.h"
#include "dijkstra.h"
#include "astar.h"

int main() {

    int rows, cols;
    char grid[MAX][MAX];

    printf("Enter rows and cols: ");
    scanf("%d %d", &rows, &cols);

    initializeGrid(grid, rows, cols);

    int sx, sy, gx, gy;

    printf("Enter Start position: ");
    scanf("%d %d", &sx, &sy);

    printf("Enter Goal position: ");
    scanf("%d %d", &gx, &gy);

    grid[sx][sy] = 'S';
    grid[gx][gy] = 'G';

    int obstacles;
    printf("Enter number of obstacles: ");
    scanf("%d", &obstacles);

    addObstacles(grid, obstacles, sx, sy, gx, gy, rows, cols);

    printf("\nOriginal Grid:\n");
    printGrid(grid, rows, cols);

    int choice;
    char tempGrid[MAX][MAX];

    do {
        printf("\n===== MENU =====\n");
        printf("1. BFS\n");
        printf("2. Dijkstra\n");
        printf("3. A*\n");
        printf("4. Run All (Compare)\n");
        printf("5. Auto Select\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 0) break;

        switch(choice) {

            // 🔹 BFS
            case 1: {
                double timeTaken;

                for(int i = 0; i < rows; i++)
                    for(int j = 0; j < cols; j++)
                        tempGrid[i][j] = grid[i][j];

                int nodes = bfs(tempGrid, rows, cols, sx, sy, gx, gy, &timeTaken);

                printf("\n--- BFS Result ---\n");
                printGrid(tempGrid, rows, cols);
                printf("Nodes Explored: %d\n", nodes);
                printf("Time Taken: %f sec\n", timeTaken);
                break;
            }

            // 🔹 Dijkstra
            case 2: {
                double timeTaken;

                for(int i = 0; i < rows; i++)
                    for(int j = 0; j < cols; j++)
                        tempGrid[i][j] = grid[i][j];

                int nodes = dijkstra(tempGrid, rows, cols, sx, sy, gx, gy, &timeTaken);

                printf("\n--- Dijkstra Result ---\n");
                printGrid(tempGrid, rows, cols);
                printf("Nodes Explored: %d\n", nodes);
                printf("Time Taken: %f sec\n", timeTaken);
                break;
            }

            // 🔹 A*
            case 3: {
                int hChoice;
                double timeTaken;

                printf("\nChoose Heuristic:\n");
                printf("1. Manhattan\n");
                printf("2. Euclidean\n");
                printf("Enter choice: ");
                scanf("%d", &hChoice);

                for(int i = 0; i < rows; i++)
                    for(int j = 0; j < cols; j++)
                        tempGrid[i][j] = grid[i][j];

                int nodes = astar(tempGrid, rows, cols, sx, sy, gx, gy, hChoice, &timeTaken);

                printf("\n--- A* Result ---\n");
                printGrid(tempGrid, rows, cols);
                printf("Nodes Explored: %d\n", nodes);
                printf("Time Taken: %f sec\n", timeTaken);
                break;
            }

            // 🔹 RUN ALL (COMPARISON)
            case 4: {
                double bfsTime, dijTime, astarTime;
                int bfsNodes, dijNodes, astarNodes;

                printf("\n=== Running All Algorithms ===\n");

                // BFS
                for(int i = 0; i < rows; i++)
                    for(int j = 0; j < cols; j++)
                        tempGrid[i][j] = grid[i][j];

                bfsNodes = bfs(tempGrid, rows, cols, sx, sy, gx, gy, &bfsTime);

                // Dijkstra
                for(int i = 0; i < rows; i++)
                    for(int j = 0; j < cols; j++)
                        tempGrid[i][j] = grid[i][j];

                dijNodes = dijkstra(tempGrid, rows, cols, sx, sy, gx, gy, &dijTime);

                // A*
                int hChoice;
                printf("Choose Heuristic for A* (1-Manhattan, 2-Euclidean): ");
                scanf("%d", &hChoice);

                for(int i = 0; i < rows; i++)
                    for(int j = 0; j < cols; j++)
                        tempGrid[i][j] = grid[i][j];

                astarNodes = astar(tempGrid, rows, cols, sx, sy, gx, gy, hChoice, &astarTime);

                // 🔥 Comparison Table
                printf("\n===== PERFORMANCE COMPARISON =====\n");
                printf("Algorithm     Nodes Explored     Time (sec)\n");
                printf("-------------------------------------------\n");
                printf("BFS           %d                 %f\n", bfsNodes, bfsTime);
                printf("Dijkstra      %d                 %f\n", dijNodes, dijTime);
                printf("A*            %d                 %f\n", astarNodes, astarTime);

                // 🔥 Best Algorithm
                int minNodes = bfsNodes;
                char bestAlgo[20] = "BFS";

                if(dijNodes < minNodes) {
                    minNodes = dijNodes;
                    sprintf(bestAlgo, "Dijkstra");
                }

                if(astarNodes < minNodes) {
                    minNodes = astarNodes;
                    sprintf(bestAlgo, "A*");
                }

                printf("\nBest Algorithm: %s (Least Nodes Explored)\n", bestAlgo);

                break;
            }

            // 🔹 AUTO SELECT
            case 5: {
                printf("\n--- Smart Auto Selection ---\n");
            
                double bfsTime, dijTime, astarTime;
                int bfsNodes, dijNodes, astarNodes;
            
                char grid1[MAX][MAX], grid2[MAX][MAX], grid3[MAX][MAX];
            
                // 🔹 Copy grid for each algorithm
                for(int i = 0; i < rows; i++) {
                    for(int j = 0; j < cols; j++) {
                        grid1[i][j] = grid[i][j];
                        grid2[i][j] = grid[i][j];
                        grid3[i][j] = grid[i][j];
                    }
                }
            
                // 🔹 Run BFS
                bfsNodes = bfs(grid1, rows, cols, sx, sy, gx, gy, &bfsTime);
            
                // 🔹 Run Dijkstra
                dijNodes = dijkstra(grid2, rows, cols, sx, sy, gx, gy, &dijTime);
            
                // 🔹 Run A* (Auto choose Manhattan)
                astarNodes = astar(grid3, rows, cols, sx, sy, gx, gy, 1, &astarTime);
            
                // 🔥 Compare (based on nodes first, then time)
                int bestNodes = bfsNodes;
                double bestTime = bfsTime;
                char bestAlgo[20] = "BFS";
                char (*bestGrid)[MAX] = grid1;
            
                if(dijNodes < bestNodes || (dijNodes == bestNodes && dijTime < bestTime)) {
                    bestNodes = dijNodes;
                    bestTime = dijTime;
                    sprintf(bestAlgo, "Dijkstra");
                    bestGrid = grid2;
                }
            
                if(astarNodes < bestNodes || (astarNodes == bestNodes && astarTime < bestTime)) {
                    bestNodes = astarNodes;
                    bestTime = astarTime;
                    sprintf(bestAlgo, "A*");
                    bestGrid = grid3;
                }
            
                // 🔥 Print comparison
                printf("\n===== PERFORMANCE =====\n");
                printf("BFS       → Nodes: %d | Time: %f\n", bfsNodes, bfsTime);
                printf("Dijkstra  → Nodes: %d | Time: %f\n", dijNodes, dijTime);
                printf("A*        → Nodes: %d | Time: %f\n", astarNodes, astarTime);
            
                // 🔥 Show best result
                printf("\nSelected Best Algorithm: %s\n", bestAlgo);
                printf("Reason: Least nodes explored + optimal path\n");
            
                printf("\nFinal Grid:\n");
                printGrid(bestGrid, rows, cols);
            
                printf("Nodes Explored: %d\n", bestNodes);
                printf("Time Taken: %f sec\n", bestTime);
            
                break;
            }

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 0);

    return 0;
}