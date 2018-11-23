#include<bits/stdc++.h>
#define LL long long int
#define MOD 1000000007
using namespace std;

LL mod_exp(LL n,LL x)
{
    if(x==0)return 1;
    if(x==1)return n;

    LL temp=mod_exp(n,x/2);
    temp=temp*temp%MOD;
    if(x%2==0)return temp;
    return n%MOD*temp%MOD;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        LL N;
        scanf("%lld",&N);

        LL first=mod_exp(2,N-1);
        LL second;
        if(N<5)second=0;
        else second=(N-2)/3;
        printf("%lld %d\n",first,second);
    }
    return 0;
}
