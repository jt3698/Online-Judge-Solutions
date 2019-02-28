#include<bits/stdc++.h>
#define LL long long int
using namespace std;

vector<LL>fibonnaci[5001];

int main()
{
    fibonnaci[0].push_back(0);
    fibonnaci[1].push_back(1);
    for(int i=2;i<=5000;i++){
        fibonnaci[i]=fibonnaci[i-1];
        for(int o=0;o<fibonnaci[i-2].size();o++)fibonnaci[i][o]+=fibonnaci[i-2][o];
        for(int o=0;o<fibonnaci[i].size();o++){
            if(fibonnaci[i][o]>=10 && o==fibonnaci[i].size()-1){
                fibonnaci[i].push_back(fibonnaci[i][o]/10);
                fibonnaci[i][o]%=10;
            }
            else if(fibonnaci[i][o]>=10){
                fibonnaci[i][o+1]+=fibonnaci[i][o]/10;
                fibonnaci[i][o]%=10;
            }
        }
    }

    int N;
    while(scanf("%d",&N)!=EOF){
        printf("The Fibonacci number for %d is ",N);
        for(int i=fibonnaci[N].size()-1;i>=0;i--)printf("%d",fibonnaci[N][i]);
        printf("\n");
    }
}
