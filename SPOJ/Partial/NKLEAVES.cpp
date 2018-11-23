#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL leaves[100001];
LL store[100001][11];
LL moving[100001],sum[100001];

struct Line
{
    LL m,c;
    int whose;
}lines[11][100001];

int no_of_lines[11];

void add_line(int id,LL mx,LL cx,int x)
{
    while(no_of_lines[id]>=2){
        Line L1=lines[id][no_of_lines[id]-1];
        Line L2=lines[id][no_of_lines[id]];
        Line L3;
        L3.m=mx;
        L3.c=cx;

        if((L2.c-L1.c)*(L2.m-L3.m)<(L3.c-L2.c)*(L1.m-L2.m))break;
        no_of_lines[id]--;
    }
    no_of_lines[id]++;
    lines[id][no_of_lines[id]].m=mx;
    lines[id][no_of_lines[id]].c=cx;
    lines[id][no_of_lines[id]].whose=x;
    return;
}

int find_best(int id,LL x)
{
    int l=1,r=no_of_lines[id];
    while(l<r){
        int mid=(l+r)/2;
        Line L1=lines[id][mid];
        Line L2=lines[id][mid+1];

        if(L2.m*x+L2.c<L1.m*x+L1.c)l=mid+1;
        else r=mid;
    }
    return lines[id][l].whose;
}

int main()
{
    int N,K;
    scanf("%d %d",&N,&K);

    for(int i=1;i<=N;i++)scanf("%lld",&leaves[i]);
    for(int i=1;i<=N;i++){
        moving[i]=moving[i-1]+leaves[i]*i;
        sum[i]=sum[i-1]+leaves[i];
    }

    for(int i=1;i<=N;i++){
        store[i][1]=moving[i]-sum[i];
        add_line(1,i*(-1),store[i-1][1]-moving[i-1]+i*sum[i-1],i);
        for(int k=2;k<=min(i,K);k++){
            store[i][k]=store[i-1][k-1];

            if(i-1>k-1){
                int best=find_best(k-1,sum[i]);
                store[i][k]=min(store[i][k],moving[i]+store[best-1][k-1]-moving[best-1]-best*sum[i]+best*sum[best-1]);
            }
            add_line(k,i*(-1),store[i-1][k]-moving[i-1]+i*sum[i-1],i);
        }
    }
    printf("%lld\n",store[N][K]);
}
