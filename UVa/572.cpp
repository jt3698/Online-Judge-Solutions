#include<bits/stdc++.h>
using namespace std;

int rows,columns;
bool visited[101][101];
bool grid[101][101];

void floodfill(int y,int x)
{
    if(!visited[y][x] && grid[y][x]){
        visited[y][x]=true;
        if(y+1<=rows)floodfill(y+1,x);
        if(y+1<=rows && x+1<=columns)floodfill(y+1,x+1);
        if(x+1<=columns)floodfill(y,x+1);
        if(y-1>=1 && x+1<=columns)floodfill(y-1,x+1);
        if(y-1>=1)floodfill(y-1,x);
        if(y-1>=1 && x-1>=1)floodfill(y-1,x-1);
        if(x-1>=1)floodfill(y,x-1);
        if(y+1<=rows && x-1>=1)floodfill(y+1,x-1);
    }
    return;
}

int main()
{
    scanf("%d %d",&rows,&columns);
    while(rows!=0){
        memset(visited,false,sizeof(visited));

        for(int y=1;y<=rows;y++){
            while(getchar()!='\n');
            for(int x=1;x<=columns;x++){
                char temp;
                temp=getchar();
                if(temp=='@')grid[y][x]=true;
                else grid[y][x]=false;
            }
        }

        int counter=0;
        for(int y=1;y<=rows;y++)
            for(int x=1;x<=columns;x++)
                if(grid[y][x] && !visited[y][x]){
                    counter++;
                    floodfill(y,x);
                }

        printf("%d\n",counter);

        scanf("%d %d",&rows,&columns);
    }
    return 0;
}
