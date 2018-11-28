#include<bits/stdc++.h>
using namespace std;

int main()
{
    string text;
    while(getline(cin,text)){
        for(int i=0;i<text.length();i++)printf("%c",text[i]-7);
        printf("\n");
    }

    return 0;
}
