#include<bits/stdc++.h>
#define LL long long int
#define MOD 1000000007
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("string"...)
#pragma GCC push_options
#pragma GCC pop_options
#pragma GCC reset_options
#pragma GCC optimize("O3")

bool add[1000001];
LL diff[1000001];
char c;

bool prime[1000001];
LL prime_list[80000];
int prime_counter=0;
void sieve()
{
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    for(int o=4;o<=1000000;o+=2)prime[o]=false;
    for(int i=3;i*i<=1000000;i+=2)if(prime[i])for(int o=i*i;o<=1000000;o+=i)prime[o]=false;
    prime_list[++prime_counter]=2;
    for(int i=3;i<=1000000;i+=2)if(prime[i])prime_list[++prime_counter]=(LL)i;
    return;
}

inline void fast(LL &D)
{
    c=getchar();
    while(c!=' ' && c!='\n'){
        D= D*=10;
        D+=c-'0';
        c=getchar();
    }
}

LL A,B,ans;
int fact[20],pri[20],maximum;

void dif(LL x)
{
    if(diff[x]!=-1)return;

    LL res=1;
    bool ad=true;
    LL temp=x;
    for(int i=1;i<=prime_counter;i++){
        if(temp==1)break;
        if(prime[temp]){
            res*=(temp-1);
            res%=MOD;
            ad=!ad;
            break;
        }
        else if(temp%prime_list[i]==0){
            while(temp%prime_list[i]==0)temp/=prime_list[i];
            res*=(prime_list[i]-1);
            res%=MOD;
            ad=!ad;
        }
    }

    diff[x]=res;
    add[x]=ad;
}

void factors(int i,LL x)
{
    if(i==maximum){
        LL smallest=A/x;
        if(smallest*x<A)smallest++;
        LL temp=(B/x+smallest)*(B/x-smallest+1);
        temp>>=1;

        dif(x);

        if(add[x])ans=(ans+diff[x]*temp%MOD)%MOD;
        else ans=(ans-diff[x]*temp%MOD+2*MOD)%MOD;
        return;
    }

    for(int o=0;o<=fact[i];o++){
       factors(i+1,x);
       x*=pri[i];
    }
    return;
}

int main()
{
    memset(diff,-1,sizeof(diff));
    diff[1]=0;
    sieve();

    LL T=0;
    fast(T);
    while(T--){
        A=0,B=0;
        fast(A);fast(B);
        maximum=0;
        LL temp=B;
        for(int i=1;i<=prime_counter;i++){
            if(temp==1)break;
            if(prime[temp]){
                pri[maximum]=temp;
                fact[maximum++]=1;
                break;
            }
            else if(temp%prime_list[i]==0){
                int l=0;
                while(temp%prime_list[i]==0){
                    l++;
                    temp/=prime_list[i];
                }
                pri[maximum]=prime_list[i];
                fact[maximum++]=l;
            }
        }

        ans=(A+B)*(B-A+1)/2;
        factors(0,1);
        printf("%lld\n",ans*B%MOD);
    }
}
