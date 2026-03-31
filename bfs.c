#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "bfs.h"

typedef struct {
    int x, y;
} Node;

Node queue[MAX * MAX];
int front, rear;

void enqueue(Node n) { queue[rear++] = n; }
Node dequeue() { return queue[front++]; }
bool isEmpty() { return front == rear; }

int bfs(char grid[MAX][MAX], int rows, int cols,
        int sx, int sy, int gx, int gy,
        double *timeTaken) {

    clock_t start = clock();

    front = rear = 0;

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    bool visited[MAX][MAX] = {false};
    Node parent[MAX][MAX];

    int nodesExplored = 0;

    enqueue((Node){sx, sy});
    visited[sx][sy] = true;

    while(!isEmpty()) {
        Node cur = dequeue();
        nodesExplored++;

        if(cur.x == gx && cur.y == gy) {

            int x = gx, y = gy;
            while(!(x == sx && y == sy)) {
                if(grid[x][y] != 'G') grid[x][y] = '*';
                Node p = parent[x][y];
                x = p.x; y = p.y;
            }

            *timeTaken = (double)(clock() - start)/CLOCKS_PER_SEC;
            return nodesExplored;
        }

        for(int i=0;i<4;i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(nx>=0 && nx<rows && ny>=0 && ny<cols &&
               !visited[nx][ny] && grid[nx][ny]!='X') {

                enqueue((Node){nx,ny});
                visited[nx][ny]=true;
                parent[nx][ny]=cur;
            }
        }
    }

    *timeTaken = (double)(clock() - start)/CLOCKS_PER_SEC;
    return nodesExplored;
}