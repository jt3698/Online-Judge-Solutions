#include<bits/stdc++.h>
#define LL long long
using namespace std;

vector<string>answers[9];

pair<string,string>split(string X)
{
    pair<string,string>res;

    for(int i=0;i<X.size()/2;i++)res.first+=X[i];
    for(int i=X.size()/2;i<X.size();i++)res.second+=X[i];

    return res;
}

LL str_to_int(string X)
{
    LL res=0;
    for(int i=0;i<X.size();i++){
        res*=10;
        res+=(X[i]-'0');
    }

    return res;
}

string int_to_str(LL X,int len)
{
    string temp;
    while(X>0){
        temp+=(X%10+'0');
        X/=10;
    }

    string res;
    for(int i=1;i<=len-temp.size();i++)res+='0';
    for(int i=temp.size()-1;i>=0;i--)res+=temp[i];

    return res;
}

void pre_compute()
{
    for(int i=2;i<=8;i+=2){
        LL N=1;
        for(int j=1;j<=i;j++)N*=10;

        for(LL k=0;k*k<N;k++){
            LL j=k*k;
            string form=int_to_str(j,i);

            pair<string,string>splitted=split(form);

            LL A=str_to_int(splitted.first),B=str_to_int(splitted.second);
            if((A+B)*(A+B)==j)answers[i].push_back(form);
        }
    }

    return;
}

int main()
{
    pre_compute();

    int N;
    while(scanf("%d",&N)!=EOF){
        for(int i=0;i<answers[N].size();i++)cout<<answers[N][i]<<'\n';
    }
}
