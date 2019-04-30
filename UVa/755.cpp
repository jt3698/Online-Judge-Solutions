#include<bits/stdc++.h>
using namespace std;

map<string,int>check;

int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        if(test>1)printf("\n");
        check.clear();

        int N;
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            string num;
            cin>>num;

            string actual="";
            for(int o=0;o<num.size();o++){
                if(num[o]>='A' && num[o]<='Y'){
                    if(num[o]<='C')actual+='2';
                    else if(num[o]<='F')actual+='3';
                    else if(num[o]<='I')actual+='4';
                    else if(num[o]<='L')actual+='5';
                    else if(num[o]<='O')actual+='6';
                    else if(num[o]<='S')actual+='7';
                    else if(num[o]<='V')actual+='8';
                    else actual+='9';
                }
                else if(num[o]>='0' && num[o]<='9')actual+=num[o];
            }

            check[actual]++;
        }

        bool have=false;
        for(map<string,int>::iterator it=check.begin();it!=check.end();it++){
            string A=it->first;
            int B=it->second;

            if(B>1){
                have=true;
                for(int o=0;o<A.size();o++){
                    if(o==3)printf("-");
                    cout<<A[o];
                }
                printf(" %d\n",B);
            }
        }
        if(!have)printf("No duplicates.\n");
    }
}
