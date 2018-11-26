#include<bits/stdc++.h>
using namespace std;

map<string,int>money;
string order[11];

int main()
{
    bool first=true;
    int N;
    while(scanf("%d",&N)!=EOF){
        if(!first)printf("\n");
        first=false;
        money.clear();

        for(int i=1;i<=N;i++)cin>>order[i];

        for(int i=1;i<=N;i++){
            string giver;
            cin>>giver;

            int amount;
            cin>>amount;

            int no_of_ppl;
            cin>>no_of_ppl;

            if(no_of_ppl>0){
                money[giver]-=(amount-amount%no_of_ppl);
                for(int i=1;i<=no_of_ppl;i++){
                    string taker;
                    cin>>taker;
                    money[taker]+=amount/no_of_ppl;
                }
            }
        }

        for(int i=1;i<=N;i++){
            cout<<order[i]<<" ";
            cout<<money[order[i]]<<"\n";
        }
    }
}
