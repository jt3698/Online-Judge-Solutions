#include<bits/stdc++.h>
using namespace std;

int main()
{
    string text;int counter=1;
    while(getline(cin,text)){
        for(int i=0;i<text.length();i++){
            if(text.at(i)=='"' && counter%2==1){cout<<"``";counter++;}
            else if(text.at(i)=='"'){cout<<"''";counter++;}
            else cout<<text.at(i);
        }
        cout<<endl;
    }
}
