#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    scanf("%d\n",&N);
    for(int i=1;i<=N;i++){
        string text;
        getline(cin,text);

        bool can=true;
        stack<bool>open;
        for(int o=0;o<text.length() && can;o++){
            if(text[o]==']'){
                if(open.empty())can=false;
                else if(open.top())can=false;
                else open.pop();
            }
            else if(text[o]=='['){
                open.push(false);
            }
            else if(text[o]==')'){
                if(open.empty())can=false;
                else if(!open.top())can=false;
                else open.pop();
            }
            else if(text[o]=='('){
                open.push(true);
            }
        }

        if(!open.empty())can=false;

        if(can)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
