#include<bits/stdc++.h>
#define LL long long int
using namespace std;

vector<LL>power(LL K,int N)
{
    vector<LL>res;
    LL temp=K;
    while(temp>0){
        res.push_back(temp%10);
        temp/=10;
    }

    for(int i=2;i<=N;i++){
        for(int o=0;o<res.size();o++)res[o]*=K;
        for(int o=0;o<res.size();o++){
            if(res[o]>=10 && o==res.size()-1)res.push_back(res[o]/10);
            else if(res[o]>=10)res[o+1]+=(res[o]/10);
            res[o]%=10;
        }
    }

    return res;
}

bool more_than(vector<LL>A,vector<LL>B)
{
    if(A.size()>B.size())return true;
    if(A.size()<B.size())return false;

    int N=A.size()-1;
    for(int i=N;i>=0;i--){
        if(A[i]>B[i])return true;
        if(A[i]<B[i])return false;
    }
}

int main()
{
    int N;
    string text_P;
    while(scanf("%d",&N)!=EOF){
        cin>>text_P;
        vector<LL>P;
        for(int i=text_P.length()-1;i>=0;i--)P.push_back(text_P[i]-'0');

        LL left=1,right=1000000000;
        while(true){
            LL mid=(left+right)/2;
            vector<LL>check=power(mid,N);
            if(check==P){
                printf("%lld\n",mid);
                break;
            }
            else if(more_than(check,P))right=mid;
            else left=mid+1;
        }
    }

    return 0;
}
