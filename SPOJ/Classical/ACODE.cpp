#include<bits/stdc++.h>
#define LL long long int
using namespace std;

int N,sequence[5001];

LL store[5001][2];
LL ways(int index,bool last_taken)
{
    if(index>N){
        if(last_taken)return 0;
        return 1;
    }

    if(store[index][last_taken]!=-1)return store[index][last_taken];

    LL ans=0;
    if(last_taken){
        int letter=sequence[index-1]*10+sequence[index];
        if(letter>=1 && letter<=26)ans+=ways(index+1,false);
    }
    else{
        int letter=sequence[index];
        if(letter>=1 && letter<=26)ans+=ways(index+1,false);
        if(letter!=0)ans+=ways(index+1,true);
    }

    return store[index][last_taken]=ans;
}

int main()
{
    string text;
    cin>>text;
    while(text!="0"){
        N=text.length();
        for(int i=0;i<N;i++)sequence[i+1]=text[i]-'0';
        memset(store,-1,sizeof(store));

        printf("%lld\n",ways(1,false));

        cin>>text;
    }
}
