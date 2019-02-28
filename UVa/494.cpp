#include<bits/stdc++.h>
using namespace std;

int main()
{
    string text;
    while(getline(cin,text)){
        int counter=0;
        bool word_check=false;
        for(int i=0;i<text.length();i++){
            if((text[i]>='A' && text[i]<='Z') || (text[i]>='a' && text[i]<='z')){
                if(!word_check){
                    counter++;
                    word_check=true;
                }
            }
            else word_check=false;
        }
        printf("%d\n",counter);
    }

    return 0;
}
