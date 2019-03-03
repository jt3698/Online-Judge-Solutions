#include<bits/stdc++.h>
using namespace std;

int prime[50001];
int primelist[5201],counter;
void sieve()
{
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    for(int i=2;i*i<=50000;i++)if(prime[i])for(int o=i*i;o<=50000;o+=i)prime[o]=false;
    for(int i=2;i<=50000;i++)if(prime[i])primelist[++counter]=i;
}

vector<int>printing;

int main()
{
    sieve();
    int N;
    scanf("%d",&N);
    while(N!=0){
        printing.clear();
        printing.push_back(N);
        if(N<0){
            printing.push_back(-1);
            N*=(-1);
        }

        for(int i=1;i<=counter && N>1;i++){
            while(N%primelist[i]==0){
                N/=primelist[i];
                printing.push_back(primelist[i]);
            }
        }

        if(N>1)printing.push_back(N);

        printf("%d = ",printing[0]);
        for(int i=1;i<printing.size();i++){
            if(i>1)printf(" x ");
            printf("%d",printing[i]);
        }
        printf("\n");

        scanf("%d",&N);
    }
}
