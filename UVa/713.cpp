#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        string A,B;
        cin>>A>>B;

        int rA[220],rB[220],counter;
        memset(rA,0,sizeof(rA));
        memset(rB,0,sizeof(rB));
        counter=210;
        for(int i=0;i<A.length();i++)rA[counter--]=(A[i]-'0');
        counter=210;
        for(int i=0;i<B.length();i++)rB[counter--]=(B[i]-'0');

        int answer[220];
        memset(answer,0,sizeof(answer));
        for(int i=210;i>=1;i--)answer[i]=rA[i]+rB[i];
        for(int i=210;i>=1;i--)while(answer[i]>=10){
            answer[i]-=10;
            answer[i-1]++;
        }
        int limit=1;
        while(answer[limit]==0)limit++;

        int back_limit=210;
        while(answer[back_limit]==0)back_limit--;

        for(int i=back_limit;i>=limit;i--)printf("%d",answer[i]);
        printf("\n");

    }
}
