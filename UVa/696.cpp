#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int M,N;
    scanf("%lld %lld",&M,&N);
    while(M!=0 || N!=0){
        long long int answer;
        if(N==1 || M==1) answer=M*N;
        else if(N==2 || M==2){
            long long int temp=M*N/2;
            long long int how_many=temp%4;
            temp/=4;
            if(how_many==0)temp=temp*2;
            else if(how_many>=2)temp=temp*2+2;
            else temp=temp*2+1;
            answer=temp*2;
        }
        else answer=M*N/2+M*N%2;

        printf("%lld knights may be placed on a %lld row %lld column board.\n",answer,M,N);

        scanf("%lld %lld",&M,&N);
    }
    return 0;
}

