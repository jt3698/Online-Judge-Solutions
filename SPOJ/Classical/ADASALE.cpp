#include<bits/stdc++.h>
#define LL long long int
using namespace std;

int N,K;
LL MOD,L[3001],P[3001];
LL trade[3001][3001],store[3001][3001];

bool visited[3001][3001];
LL most_value[3001];

int main()
{
    scanf("%d %d %lld",&N,&K,&MOD);
    for(int i=1;i<=N;i++)scanf("%lld",&L[i]);
    for(int i=1;i<=N;i++)scanf("%lld",&P[i]);

    for(int i=1;i<=N;i++){
        LL cost_now=0;
        for(int o=1;o<=K;o++){
            cost_now+=(P[i]*(LL)o*(LL)i%MOD);
            trade[i][o]=cost_now;
        }
    }
    for(int i=1;i<=N;i++)most_value[i]=-10e8;
    for(int items=0;items<=K;items++){
        store[N][items]=max(0LL,trade[N][items]-L[N]);
        most_value[N]=max(most_value[N],store[N][items]-trade[N-1][items]);
    }
    for(int city=N-1;city>=1;city--){
        for(int items=0;items<=K;items++){
            store[city][items]=max(store[city][items],trade[city][items]-L[city]+most_value[city+1]);
            store[city][items]=max(store[city][items],store[city+1][items]);
            most_value[city]=max(most_value[city],store[city][items]-trade[city-1][items]);
        }
    }
    printf("%lld\n",store[1][0]);

}
