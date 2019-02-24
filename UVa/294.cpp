#include<bits/stdc++.h>
#define LL long long int
using namespace std;

bool prime[32001];
int prime_list[3500];
int counter=0;

void sieve()
{
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    for(int i=2;i*i<=32000;i++)if(prime[i])for(int o=i*i;o<=32000;o+=i)prime[o]=false;
    for(int i=2;i<=32000;i++)if(prime[i])prime_list[++counter]=i;
    return;
}

int main()
{
    sieve();
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        LL l,r;
        scanf("%lld %lld",&l,&r);
        LL A,B=-1;
        for(LL o=l;o<=r;o++){
            LL divisors=1;
            LL temp=o;
            for(int i=1;i<=counter && temp>1;i++){
                if(temp%prime_list[i]==0){
                    LL c=1;
                    while(temp%prime_list[i]==0){
                        temp/=prime_list[i];
                        c++;
                    }
                    divisors*=c;
                }
            }
            if(divisors>B){
                B=divisors;
                A=o;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,r,A,B);
    }
}
