#include<bits/stdc++.h>
using namespace std;

int main()
{
    int grid[101][101];
    int sum_grid[101][101];

    int N;
    scanf("%d",&N);
    for(int y=0;y<=N;y++)grid[y][0]=0;
    for(int x=0;x<=N;x++)grid[0][x]=0;
    for(int y=1;y<=N;y++)for(int x=1;x<=N;x++)scanf("%d",&grid[y][x]);

    for(int y=1;y<=N;y++)for(int x=1;x<=N;x++)sum_grid[y][x]=grid[y][x]+sum_grid[y-1][x]+sum_grid[y][x-1]-sum_grid[y-1][x-1];

    int max_sum=-1e8;
    for(int y=1;y<=N;y++)for(int x=1;x<=N;x++)for(int y1=0;y1<y;y1++)for(int x1=0;x1<x;x1++)max_sum=max(max_sum,sum_grid[y][x]-sum_grid[y1][x]-sum_grid[y][x1]+sum_grid[y1][x1]);

    printf("%d\n",max_sum);
}
