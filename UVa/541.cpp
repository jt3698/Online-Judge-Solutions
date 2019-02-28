#include<bits/stdc++.h>
using namespace std;

int grid[101][101];

int main()
{
    int N;
    scanf("%d",&N);
    while(N!=0){
        for(int y=1;y<=N;y++)for(int x=1;x<=N;x++)scanf("%d",&grid[y][x]);
        vector<int>rows,cols;
        for(int y=1;y<=N;y++){
            int counter=0;
            for(int x=1;x<=N;x++)counter+=grid[y][x];
            if(counter%2==1)rows.push_back(y);
        }
        for(int x=1;x<=N;x++){
            int counter=0;
            for(int y=1;y<=N;y++)counter+=grid[y][x];
            if(counter%2==1)cols.push_back(x);
        }
        if(rows.size()==0 && cols.size()==0)printf("OK\n");
        else if(rows.size()==1 && cols.size()==1)printf("Change bit (%d,%d)\n",rows[0],cols[0]);
        else printf("Corrupt\n");

        scanf("%d",&N);
    }
}
