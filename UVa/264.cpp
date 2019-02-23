#include<bits/stdc++.h>
using namespace std;

int main()
{
    int term;
    while(scanf("%d",&term)!=EOF){
        bool side=false;
        int index=1,counter=1;
        while(index+counter<=term){
            index+=counter;
            counter++;
            side=!side;
        }
        int difference=term-index;
        if(side)printf("TERM %d IS %d/%d\n",term,1+difference,counter-difference);
        else printf("TERM %d IS %d/%d\n",term,counter-difference,1+difference);
    }
}
