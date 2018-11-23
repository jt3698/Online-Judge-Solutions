#include<bits/stdc++.h>
using namespace std;

char grid[1001][1001];
int visited[1001][1001];
pair<int,int>maximum;
int columns,rows;

void DepthFirstSearch(int y,int x,int counter)
{
    visited[y][x]=counter;
    if(counter>visited[maximum.first][maximum.second])maximum=make_pair(y,x);
    if(y+1<=rows){
        if(visited[y+1][x]==-1 && grid[y+1][x]=='.')DepthFirstSearch(y+1,x,counter+1);
    }
    if(y-1>=1){
        if(visited[y-1][x]==-1 && grid[y-1][x]=='.')DepthFirstSearch(y-1,x,counter+1);
    }
    if(x+1<=columns){
        if(visited[y][x+1]==-1 && grid[y][x+1]=='.')DepthFirstSearch(y,x+1,counter+1);
    }
    if(x-1>=1){
        if(visited[y][x-1]==-1 && grid[y][x-1]=='.')DepthFirstSearch(y,x-1,counter+1);
    }
    return;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        scanf("%d %d",&columns,&rows);
        for(int y=1;y<=rows;y++){
            while(getchar()!='\n');
            for(int x=1;x<=columns;x++)grid[y][x]=getchar();
        }
        bool done=false;
        for(int y=1;y<=rows && !done;y++)for(int x=1;x<=columns && !done;x++)if(grid[y][x]=='.'){
            memset(visited,-1,sizeof(visited));
            visited[y][x]=0;
            maximum.first=y;
            maximum.second=x;
            DepthFirstSearch(y,x,0);
            done=true;
        }
        memset(visited,-1,sizeof(visited));
        visited[maximum.first][maximum.second]=0;
        DepthFirstSearch(maximum.first,maximum.second,0);
        printf("Maximum rope length is %d.\n",visited[maximum.first][maximum.second]);
    }
}
