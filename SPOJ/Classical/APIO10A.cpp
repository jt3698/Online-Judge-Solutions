#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL soldiers[1000001],sum[1000001];
LL A,B,C;
LL store[1000001];

struct Line
{
    LL m,c;
    int whose;
}lines[1000001];

int no_of_lines;

void add_line(LL mx,LL cx,int x)
{
    while(no_of_lines>=2){
        Line L1=lines[no_of_lines-1];
        Line L2=lines[no_of_lines];
        Line L3;
        L3.m=mx;
        L3.c=cx;

        if((L2.c-L3.c)*(L2.m-L1.m)>(L1.c-L2.c)*(L3.m-L2.m))break;
        no_of_lines--;
    }
    no_of_lines++;
    lines[no_of_lines].m=mx;
    lines[no_of_lines].c=cx;
    lines[no_of_lines].whose=x;
    return;
}

int find_best(LL x)
{
    int l=1,r=no_of_lines;
    while(l<r){
        int mid=(l+r)/2;
        Line L1=lines[mid];
        Line L2=lines[mid+1];
        if(L2.m*x+L2.c>L1.m*x+L1.c)l=mid+1;
        else r=mid;
    }
    return lines[l].whose;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        int N;
        scanf("%d",&N);
        scanf("%lld %lld %lld",&A,&B,&C);
        for(int i=1;i<=N;i++){
            scanf("%lld",&soldiers[i]);
            sum[i]=sum[i-1]+soldiers[i];
        }

        no_of_lines=0;
        for(int i=1;i<=N;i++){
            store[i]=store[i-1]+A*soldiers[i]*soldiers[i]+B*soldiers[i]+C;
            if(i>1){
                int best=find_best(sum[i]);
                store[i]=max(store[i],store[best-1]+A*(sum[i]-sum[best-1])*(sum[i]-sum[best-1])+B*(sum[i]-sum[best-1])+C);
            }
            add_line(A*(-2)*sum[i-1],store[i-1]+A*sum[i-1]*sum[i-1]-B*sum[i-1],i);
        }
        printf("%lld\n",store[N]);
    }
}
