#include<bits/stdc++.h>
//#define char() char_unlocked()
using namespace std;

int max_change[101];
int store[101][10001];
int keeping[102];
char c;

struct Coin
{
    int value;
    int trade;
    int keep;
    int how_many;
}coins[101];

int N,C;

int minimum_cost(int coin_no,int money)
{
    if(store[coin_no][money]!=-1)return store[coin_no][money];

    int ans=-2;
    int new_money,adding,res;
    for(int i=0;i<=coins[coin_no].how_many;i++){
        new_money=money+i*coins[coin_no].value;
        adding=i*coins[coin_no].trade+(coins[coin_no].how_many-i)*coins[coin_no].keep;
        if(new_money-C<=100){
            if(new_money>=C){
                if(max_change[new_money-C]!=-1){
                    if(ans==-2)ans=adding+max_change[new_money-C]+keeping[coin_no+1];
                    else ans=min(ans,adding+max_change[new_money-C]+keeping[coin_no+1]);
                }
            }
            if(coin_no<N){
                res=minimum_cost(coin_no+1,new_money);
                if(res>=0){
                    if(ans==-2)ans=res+adding;
                    else ans=min(ans,res+adding);
                }
            }
        }
    }

    return store[coin_no][money]=ans;
}

int main()
{
    int T;
    T=0;
    c=getchar();
    while(c!=' ' && c!='\n'){
        T*=10;
        T+=(c-'0');
        c=getchar();
    }

    for(int test=1;test<=T;test++){
        N=0;
        c=getchar();
        while(c!=' ' && c!='\n'){
            N*=10;
            N+=(c-'0');
            c=getchar();
        }
        C=0;
        c=getchar();
        while(c!=' ' && c!='\n'){
            C*=10;
            C+=(c-'0');
            c=getchar();
        }
        for(int i=1;i<=N;i++){
            coins[i].value=0;
            c=getchar();
            while(c!=' ' && c!='\n'){
                coins[i].value*=10;
                coins[i].value+=(c-'0');
                c=getchar();
            }
            coins[i].trade=0;
            c=getchar();
            while(c!=' ' && c!='\n'){
                coins[i].trade*=10;
                coins[i].trade+=(c-'0');
                c=getchar();
            }
            coins[i].keep=0;
            c=getchar();
            while(c!=' ' && c!='\n'){
                coins[i].keep*=10;
                coins[i].keep+=(c-'0');
                c=getchar();
            }
        }
        int sum=0;
        for(int i=1;i<=N;i++){
            coins[i].how_many=0;
            c=getchar();
            while(c!=' ' && c!='\n'){
                coins[i].how_many*=10;
                coins[i].how_many+=(c-'0');
                c=getchar();
            }
            sum+=coins[i].how_many*coins[i].value;
        }
        memset(max_change,-1,sizeof(max_change));
        max_change[0]=0;
        for(int i=0;i<=sum;i++){
            if(max_change[i]!=-1){
                for(int o=1;o<=N;o++)if(i+coins[o].value<=100)
                    max_change[i+coins[o].value]=max(max_change[i+coins[o].value],max_change[i]+coins[o].trade+coins[o].keep);
            }
        }

        keeping[N+1]=0;
        for(int i=N;i>=1;i--)keeping[i]=keeping[i+1]+coins[i].keep*coins[i].how_many;

        memset(store,-1,sizeof(store));
        int ans=minimum_cost(1,0);
        if(ans<0)printf("Scenario #%d: -1\n",test);
        else printf("Scenario #%d: %d\n",test,ans);
    }

    return 0;
}
