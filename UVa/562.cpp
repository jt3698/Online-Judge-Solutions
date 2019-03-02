#include<bits/stdc++.h>
using namespace std;

int coins[200];
int sum[101][50001];

int minimum_difference(int no_of_coins, int other_sum,int total)
{

    if(no_of_coins==0)return abs(other_sum*2-total);
    if(sum[no_of_coins][other_sum]!=-1)return sum[no_of_coins][other_sum];

    return sum[no_of_coins][other_sum]=min(minimum_difference(no_of_coins-1,other_sum+coins[no_of_coins],total),minimum_difference(no_of_coins-1,other_sum,total));
}

int main()
{
    int T;
    cin>>T;
    for(int test=1;test<=T;test++){
        memset(sum,-1,sizeof(sum));

        int N;
        cin>>N;

        int total=0;
        for(int i=1;i<=N;i++){
            cin>>coins[i];
            total+=coins[i];
        }

        cout<<minimum_difference(N,0,total)<<endl;
    }
}
