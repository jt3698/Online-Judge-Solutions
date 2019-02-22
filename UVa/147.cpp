#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL dp[6001];
int coins[12];

int main()
{
    coins[1]=1;
    coins[2]=2;
    coins[3]=4;
    coins[4]=10;
    coins[5]=20;
    coins[6]=40;
    coins[7]=100;
    coins[8]=200;
    coins[9]=400;
    coins[10]=1000;
    coins[11]=2000;

    dp[0]=1;
    for(int i=1;i<=11;i++)
        for(int j=coins[i];j<=6000;j++)
            dp[j]+=dp[j-coins[i]];

    int D,C;
    scanf("%d.%d",&D,&C);
    while(D!=0 || C!=0){
        if(D<10)printf(" ");
        if(D<100)printf(" ");

        printf("%d.",D);
        if(C<10)printf("0");
        printf("%d",C);

        LL res=dp[(D*100+C)/5];
        int spaces=17;
        LL temp=res;
        while(temp>0){
            spaces--;
            temp/=10;
        }

        for(int i=1;i<=spaces;i++)printf(" ");
        printf("%lld\n",res);

        scanf("%d.%d",&D,&C);
    }
}
