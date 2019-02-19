#include<bits/stdc++.h>
using namespace std;

int rows,columns;
int grid[11][101];
int path[11][101];

int store[11][101];
int travel(int row,int column)
{
    if(column==columns){
        path[row][column]=0;
        return grid[row][column];
    }

    if(store[row][column]!=-1)return store[row][column];

    int next_row;

    next_row=(row+rows-2)%rows+1;
    int minimum=travel((row+rows-2)%rows+1,column+1);

    int A=travel(row,column+1);
    if(A<minimum || A==minimum && row<next_row){
        minimum=A;
        next_row=row;
    }
    int B=travel(row%rows+1,column+1);
    if(B<minimum || B==minimum && row%rows+1<next_row){
        minimum=B;
        next_row=row%rows+1;
    }

    path[row][column]=next_row;
    return store[row][column]=minimum+grid[row][column];
}

int main()
{
    while(cin>>rows>>columns){
        memset(store,-1,sizeof(store));
        for(int y=1;y<=rows;y++)for(int x=1;x<=columns;x++)scanf("%d",&grid[y][x]);

        int start=1;
        int minimum=travel(1,1);
        for(int i=2;i<=rows;i++){
            int A=travel(i,1);
            if(A<minimum){
                minimum=A;
                start=i;
            }
        }
        int column=1;
        while(start!=0){
            printf("%d",start);
            if(column<columns)printf(" ");
            start=path[start][column++];
        }
        printf("\n%d\n",minimum);
    }
}
