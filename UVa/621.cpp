#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int test=1;test<=T;test++){
        string number;
        cin>>number;
        if(number=="1" || number=="4" || number=="78")cout<<"+\n";
        else if(number.at(number.length()-1)=='5' && number.at(number.length()-2)=='3')cout<<"-\n";
        else if(number.at(0)=='9' && number.at(number.length()-10=='4'))cout<<"*\n";
        else cout<<"?\n";
    }
}
