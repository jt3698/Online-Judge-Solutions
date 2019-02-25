#include<bits/stdc++.h>
#define LL long long int
using namespace std;

LL pascal[101][101];

int main()
{
    pascal[0][0]=1;
    for(int i=1;i<=100;i++){
        pascal[i][0]=1;
        pascal[i][i]=1;
        for(int o=1;o<i;o++){
            if(pascal[i-1][o-1]==-1 || pascal[i-1][o]==-1)pascal[i][o]=-1;
            else pascal[i][o]=pascal[i-1][o-1]+pascal[i-1][o];
            if(pascal[i][o]>(1LL<<33))pascal[i][o]=-1;
        }
    }

    int N,M;
    scanf("%d %d",&N,&M);
    while(N!=0 || M!=0){
        printf("%d things taken %d at a time is %lld exactly.\n",N,M,pascal[N][M]);
        scanf("%d %d",&N,&M);
    }
}
