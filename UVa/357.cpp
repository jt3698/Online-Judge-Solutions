#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int change[30001];
    change[0]=1;
    for(int i=1;i<=30000;i++)change[i]=change[i-1];
    for(int i=5;i<=30000;i++)change[i]+=change[i-5];
    for(int i=10;i<=30000;i++)change[i]+=change[i-10];
    for(int i=25;i<=30000;i++)change[i]+=change[i-25];
    for(int i=50;i<=30000;i++)change[i]+=change[i-50];

    int value;
    while(cin>>value)
        if(change[value]==1)cout<<"There is only "<<change[value]<<" way to produce "<<value<<" cents change."<<endl;
        else cout<<"There are "<<change[value]<<" ways to produce "<<value<<" cents change."<<endl;
}

