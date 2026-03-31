#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>
#include "dijkstra.h"

typedef struct {
    int x, y, cost;
} Node;

Node pq[MAX * MAX];
int size;

void push(Node n) { pq[size++] = n; }

Node pop() {
    int minIndex = 0;
    for(int i=1;i<size;i++)
        if(pq[i].cost < pq[minIndex].cost)
            minIndex = i;

    Node res = pq[minIndex];
    pq[minIndex] = pq[--size];
    return res;
}

int dijkstra(char grid[MAX][MAX], int rows, int cols,
             int sx, int sy, int gx, int gy,
             double *timeTaken) {

    clock_t start = clock();

    size = 0;

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    int dist[MAX][MAX];
    bool visited[MAX][MAX]={false};
    Node parent[MAX][MAX];

    int nodesExplored = 0;

    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            dist[i][j]=INT_MAX;

    dist[sx][sy]=0;
    push((Node){sx,sy,0});

    while(size>0) {
        Node cur = pop();
        nodesExplored++;

        if(visited[cur.x][cur.y]) continue;
        visited[cur.x][cur.y]=true;

        if(cur.x==gx && cur.y==gy) {

            int x=gx,y=gy;
            while(!(x==sx && y==sy)) {
                if(grid[x][y]!='G') grid[x][y]='*';
                Node p=parent[x][y];
                x=p.x; y=p.y;
            }

            *timeTaken = (double)(clock()-start)/CLOCKS_PER_SEC;
            return nodesExplored;
        }

        for(int i=0;i<4;i++) {
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];

            if(nx>=0 && nx<rows && ny>=0 && ny<cols &&
               !visited[nx][ny] && grid[nx][ny]!='X') {

                int newCost = dist[cur.x][cur.y]+1;

                if(newCost < dist[nx][ny]) {
                    dist[nx][ny]=newCost;
                    push((Node){nx,ny,newCost});
                    parent[nx][ny]=cur;
                }
            }
        }
    }

    *timeTaken = (double)(clock()-start)/CLOCKS_PER_SEC;
    return nodesExplored;
}