#include<bits/stdc++.h>
#define LL long long
using namespace std;

struct BigInt
{
    LL digits[10001];
    int biggest=0;
} factorials[1001];

int main()
{
    factorials[0].digits[1]=1;
    factorials[0].biggest=1;

    for(LL i=1;i<=1000;i++){
        factorials[i]=factorials[i-1];

        for(int j=1;j<=factorials[i].biggest;j++)
            factorials[i].digits[j]*=i;

        for(int j=1;j<=factorials[i].biggest;j++){
            if(factorials[i].digits[j]>100000000 && j==factorials[i].biggest)factorials[i].biggest++;

            if(factorials[i].digits[j]>100000000)factorials[i].digits[j+1]+=factorials[i].digits[j]/100000000;

            factorials[i].digits[j]%=100000000;
        }
    }

    int N;
    while(scanf("%d",&N)!=EOF){
        printf("%d!\n",N);

        for(int i=factorials[N].biggest;i>=1;i--){
            int zeros=8;
            LL temp=factorials[N].digits[i];
            while(temp>0){
                zeros--;
                temp/=10;
            }

            if(i!=factorials[N].biggest)for(int j=1;j<=zeros;j++)printf("0");
            if(factorials[N].digits[i]!=0)printf("%lld",factorials[N].digits[i]);
        }

        printf("\n");
    }

    return 0;
}
