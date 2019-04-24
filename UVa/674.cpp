#include<bits/stdc++.h>
using namespace std;

int main()
{
    int change[8001];
    change[0]=1;
    for(int i=1;i<=8000;i++)change[i]=change[i-1];
    for(int i=5;i<=8000;i++)change[i]+=change[i-5];
    for(int i=10;i<=8000;i++)change[i]+=change[i-10];
    for(int i=25;i<=8000;i++)change[i]+=change[i-25];
    for(int i=50;i<=8000;i++)change[i]+=change[i-50];

    int value;
    while(cin>>value)cout<<change[value]<<endl;
}

