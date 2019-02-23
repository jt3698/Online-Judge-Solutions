#include<bits/stdc++.h>
using namespace std;

bool works(vector<int>check)
{
    bool diagonals[31];
    memset(diagonals,false,sizeof(diagonals));
    for(int i=0;i<check.size();i++){
        pair<int,int>index=make_pair(check[i]+i,15+check[i]+8-i-1);
        if(diagonals[index.first])return false;
        if(diagonals[index.second])return false;
        diagonals[index.first]=true;
        diagonals[index.second]=true;
    }
    return true;
}

int main()
{
    vector<int>combination;
    vector<vector<int> >working_combinations;
    for(int i=1;i<=8;i++)combination.push_back(i);
    do{
        if(works(combination))working_combinations.push_back(combination);
    }while(next_permutation(combination.begin(),combination.end()));

    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        int grid[9][9];
        for(int y=1;y<=8;y++)for(int x=1;x<=8;x++)scanf("%d",&grid[y][x]);

        int maximum=-1;
        for(int i=0;i<working_combinations.size();i++){
            int temp=0;
            for(int j=0;j<working_combinations[i].size();j++)temp+=grid[j+1][working_combinations[i][j]];
            maximum=max(maximum,temp);
        }

        int temp=maximum;
        int digits=0;
        while(temp>0){
            digits++;
            temp/=10;
        }
        for(int i=5;i>digits;i--)printf(" ");
        printf("%d\n",maximum);
    }
}
