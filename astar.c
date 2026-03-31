#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "astar.h"

typedef struct {
    int x,y,g,h,f;
} Node;

Node openList[MAX*MAX];
int astarSize;

void astarPush(Node n){ openList[astarSize++]=n; }

Node astarPop(){
    int minIndex=0;
    for(int i=1;i<astarSize;i++)
        if(openList[i].f < openList[minIndex].f)
            minIndex=i;

    Node res=openList[minIndex];
    openList[minIndex]=openList[--astarSize];
    return res;
}

int heuristic(int x,int y,int gx,int gy,int type){
    if(type==1) return abs(x-gx)+abs(y-gy);
    else return (int)sqrt((x-gx)*(x-gx)+(y-gy)*(y-gy));
}

int astar(char grid[MAX][MAX], int rows, int cols,
          int sx, int sy, int gx, int gy,
          int type, double *timeTaken){

    clock_t start = clock();

    astarSize=0;

    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};

    int gCost[MAX][MAX];
    bool visited[MAX][MAX]={false};
    Node parent[MAX][MAX];

    int nodesExplored=0;

    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            gCost[i][j]=INT_MAX;

    gCost[sx][sy]=0;
    int h=heuristic(sx,sy,gx,gy,type);

    astarPush((Node){sx,sy,0,h,h});

    while(astarSize>0){

        Node cur=astarPop();
        nodesExplored++;

        if(visited[cur.x][cur.y]) continue;
        visited[cur.x][cur.y]=true;

        if(cur.x==gx && cur.y==gy){

            int x=gx,y=gy;
            while(!(x==sx && y==sy)){
                if(grid[x][y]!='G') grid[x][y]='*';
                Node p=parent[x][y];
                x=p.x; y=p.y;
            }

            *timeTaken = (double)(clock()-start)/CLOCKS_PER_SEC;
            return nodesExplored;
        }

        for(int i=0;i<4;i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];

            if(nx>=0 && nx<rows && ny>=0 && ny<cols &&
               grid[nx][ny]!='X' && !visited[nx][ny]){

                int newG=gCost[cur.x][cur.y]+1;

                if(newG<gCost[nx][ny]){
                    gCost[nx][ny]=newG;

                    int h=heuristic(nx,ny,gx,gy,type);
                    int f=newG+h;

                    astarPush((Node){nx,ny,newG,h,f});
                    parent[nx][ny]=cur;
                }
            }
        }
    }

    *timeTaken = (double)(clock()-start)/CLOCKS_PER_SEC;
    return nodesExplored;
}