#include<bits/stdc++.h>
#define LL long long int
using namespace std;

int main()
{
    string binary;
    cin>>binary;
    while(binary!="0"){
        int exp=binary.length();

        LL denary=0;
        for(int i=0;i<binary.length();i++){
            LL adding=1;
            for(int o=1;o<=exp;o++)adding*=2;

            denary+=(binary.at(i)-'0')*(adding-1);
            exp--;
        }
        printf("%lld\n",denary);

        cin>>binary;
    }
}
