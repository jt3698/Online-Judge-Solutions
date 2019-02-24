#include<bits/stdc++.h>
using namespace std;

bool board[33][33];
int counter;

void color(int x1,int y1,int x2,int y2)
{
    char type=getchar();
    if(type=='p'){
        color((x1+x2)/2+1,y1,x2,(y1+y2)/2);
        color(x1,y1,(x1+x2)/2,(y1+y2)/2);
        color(x1,(y1+y2)/2+1,(x1+x2)/2,y2);
        color((x1+x2)/2+1,(y1+y2)/2+1,x2,y2);
    }
    else if(type=='f')
        for(int x=x1;x<=x2;x++)for(int y=y1;y<=y2;y++)if(!board[x][y]){
            board[x][y]=true;
            counter++;
        }

    return;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        counter=0;
        memset(board,false,sizeof(board));
        while(getchar()!='\n');
        color(1,1,32,32);
        while(getchar()!='\n');
        color(1,1,32,32);

        printf("There are %d black pixels.\n",counter);
    }

    return 0;
}
