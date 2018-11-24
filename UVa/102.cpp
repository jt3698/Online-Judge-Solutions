#include<bits/stdc++.h>
using namespace std;

int main()
{
    int B[4],G[4],C[4];
    while(scanf("%d %d %d %d %d %d %d %d %d",&B[1],&G[1],&C[1],&B[2],&G[2],&C[2],&B[3],&G[3],&C[3])!=EOF){
        vector<int>order;
        pair<int,string>minimum;
        minimum.first=10e9;
        for(int i=1;i<=3;i++)order.push_back(i);
        do{
            int moving=0;
            if(order[0]==1)moving=moving+B[2]+B[3];
            if(order[0]==2)moving=moving+G[2]+G[3];
            if(order[0]==3)moving=moving+C[2]+C[3];
            if(order[1]==1)moving=moving+B[1]+B[3];
            if(order[1]==2)moving=moving+G[1]+G[3];
            if(order[1]==3)moving=moving+C[1]+C[3];
            if(order[2]==1)moving=moving+B[1]+B[2];
            if(order[2]==2)moving=moving+G[1]+G[2];
            if(order[2]==3)moving=moving+C[1]+C[2];

            string name="";
            for(int i=0;i<order.size();i++){
                if(order[i]==1)name+='B';
                if(order[i]==2)name+='G';
                if(order[i]==3)name+='C';
            }
            if(moving<minimum.first)minimum=make_pair(moving,name);
            else if(moving==minimum.first)if(name<minimum.second)minimum=make_pair(moving,name);

        }while(next_permutation(order.begin(),order.end()));

        cout<<minimum.second<<" "<<minimum.first<<endl;
    }
}
