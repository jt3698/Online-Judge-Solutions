#include<bits/stdc++.h>
using namespace std;

int main()
{
    string text;
    while(getline(cin,text)){
        int counter[53];
        memset(counter,0,sizeof(counter));
        for(int i=0;i<text.size();i++){
            if(text[i]>='a' && text[i]<='z')counter[text[i]-'a'+27]++;
            else if(text[i]>='A' && text[i]<='Z')counter[text[i]-'A'+1]++;
        }
        int maximum=-1;
        for(int i=1;i<=52;i++)maximum=max(maximum,counter[i]);
        for(int i=1;i<=52;i++)if(maximum==counter[i]){
            if(i<=26)printf("%c",i-1+'A');
            else printf("%c",i-27+'a');
        }
        printf(" %d\n",maximum);
    }
}
