#include<bits/stdc++.h>
using namespace std;

int N;
int best;
vector<int>best_ans;

int tracks,lengths[21];

void finding(int idx,vector<int>chosen,int total)
{
    for(int i=idx;i<=tracks;i++){
        if(total+lengths[i]<=N){
            vector<int>temp=chosen;
            temp.push_back(lengths[i]);
            if(total+lengths[i]>best){
                best_ans=temp;
                best=total+lengths[i];
            }
            finding(i+1,temp,total+lengths[i]);
        }
    }

    return;
}

int main()
{
    while(scanf("%d",&N)!=EOF){
        best=0;
        best_ans.clear();

        scanf("%d",&tracks);
        for(int i=1;i<=tracks;i++)scanf("%d",&lengths[i]);

        vector<int>emp;
        finding(1,emp,0);

        for(int i=0;i<best_ans.size();i++)printf("%d ",best_ans[i]);
        printf("sum:%d\n",best);
    }
}
