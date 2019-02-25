#include<bits/stdc++.h>
using namespace std;

char grid[51][51];
int N;

void floodfill(int x,int y)
{
    if(grid[x][y]=='0')return;

    grid[x][y]='0';

    if(x<N)floodfill(x+1,y);
    if(x>1)floodfill(x-1,y);
    if(y<N)floodfill(x,y+1);
    if(y>1)floodfill(x,y-1);

    if(x<N && y<N)floodfill(x+1,y+1);
    if(x<N && y>1)floodfill(x+1,y-1);
    if(x>1 && y<N)floodfill(x-1,y+1);
    if(x>1 && y>1)floodfill(x-1,y-1);

    return;
}

int main()
{
    int test=0;
    while(cin>>N){
        test++;

        for(int i=1;i<=N;i++){
            string temp;
            cin>>temp;
            for(int j=0;j<N;j++)grid[i][j+1]=temp[j];
        }

        int ans=0;
        for(int x=1;x<=N;x++)for(int y=1;y<=N;y++)if(grid[x][y]=='1'){
            ans++;
            floodfill(x,y);
        }

        cout<<"Image number "<<test<<" contains "<<ans<<" war eagles.\n";
    }
}
