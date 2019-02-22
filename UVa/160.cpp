#include<bits/stdc++.h>
using namespace std;

int prime_no[101];
bool prime[101];

void sieve()
{
    memset(prime,true,sizeof(prime));
    prime[1]=false;

    int counter=0;

    for(int i=2;i*i<=100;i++)if(prime[i])for(int o=i*i;o<=100;o+=i)prime[o]=false;
    for(int i=1;i<=100;i++)if(prime[i])prime_no[i]=++counter;

    return;
}

int contains[101][101],actual[101][101];
vector<int>really[101];

void pre_compute()
{
    for(int i=1;i<=100;i++){
        int temp=i;
        int c=2;
        while(temp>1){
            while(temp%c==0){
                contains[i][prime_no[c]]++;
                temp/=c;
            }
            c++;
        }
    }

    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)actual[i][j]=actual[i-1][j]+contains[i][j];

    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)if(actual[i][j]>0)really[i].push_back(actual[i][j]);

    return;
}

int main()
{
    sieve();
    pre_compute();

    int N;
    scanf("%d",&N);
    while(N!=0){
        if(N<100)printf(" ");
        if(N<10)printf(" ");

        printf("%d! =",N);
        for(int i=0;i<really[N].size();i++){
            if(i%15==0 && i!=0)printf("\n      ");

            if(really[N][i]<100)printf(" ");
            if(really[N][i]<10)printf(" ");
            printf("%d",really[N][i]);
        }
        printf("\n");

        scanf("%d",&N);
    }
}
