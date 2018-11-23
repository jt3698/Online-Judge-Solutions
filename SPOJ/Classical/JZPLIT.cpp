#include<bits/stdc++.h>
using namespace std;

bool grid[1001][1001],solution[1001][1001];
int row_count[1001],col_count[1001];

int fast()
{
    int res=0;
    char c=getchar_unlocked();
    while(c!=' ' && c!='\n'){
        res*=10;
        res+=(c-'0');
        c=getchar_unlocked();
    }
    return res;
}

int main()
{
    int r,c;
    r=fast();
    c=fast();

    for(int y=1;y<=r;y++){
        for(int x=1;x<=c;x++)grid[y][x]=getchar_unlocked()-'0';
        while(getchar_unlocked()!='\n');
    }
    for(int y=1;y<=r;y++)for(int x=1;x<=c;x++)
        if(grid[y][x]){
            row_count[y]++;
            col_count[x]++;
        }
    for(int y=1;y<=r;y++)for(int x=1;x<=c;x++)solution[y][x]=(row_count[y]+col_count[x]-grid[y][x])&1;
    if(!(r&1) && !(c&1)){
        for(int y=1;y<=r;y++){
            for(int x=1;x<=c;x++)putchar_unlocked('0'+solution[y][x]);
            putchar_unlocked('\n');
        }
        return 0;
    }

    int A=0,B=0;
    for(int x=1;x<=c;x++)A+=solution[1][x];
    for(int y=1;y<=r;y++)B+=solution[y][1];
    bool check=(A+B-solution[1][1])&1;
    if(check^grid[1][1]){
        if(r&1)
            for(int y=1;y<=r;y++)solution[y][1]^=1;
        else
            for(int x=1;x<=c;x++)solution[1][x]^=1;
    }

    for(int y=1;y<=r;y++){
        for(int x=1;x<=c;x++)putchar_unlocked('0'+solution[y][x]);
        putchar_unlocked('\n');
    }
    return 0;
}
