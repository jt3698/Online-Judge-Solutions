#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL store[1001][1001];

LL pascal(LL row,LL spot)
{
    if(spot==1 || spot==row)return 1;

    if(store[row][spot]!=-1)return store[row][spot];

    return store[row][spot]=pascal(row-1,spot)+pascal(row-1,spot-1);
}

LL priming(LL N,LL K)
{
    int twos=0,threes=0;

    if(K>4)K=N-K;

    for(int i=1;i<=K;i++){
        int temp=i;
        while(temp%2==0){
            twos++;
            temp/=2;
        }
        while(temp%3==0){
            threes++;
            temp/=3;
        }
    }

    LL ans=1;
    for(LL i=N;i>=N-K+1;i--){
        LL temp=i;
        while(temp%2==0 && twos>0){
            temp/=2;
            twos--;
        }
        while(temp%3==0 && threes>0){
            temp/=3;
            threes--;
        }
        ans*=temp;
    }

    return ans;
}

int main()
{
    memset(store,-1,sizeof(store));

    LL N,K;
    scanf("%lld %lld",&N,&K);
    while(N!=0 || K!=0){
        if(N<1000)printf("%lld\n",pascal(N+1,K+1));
        else printf("%lld\n",priming(N,K));

        scanf("%lld %lld",&N,&K);
    }
}
