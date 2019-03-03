#include<bits/stdc++.h>
using namespace std;

vector<int>connections[27];
bool cycle,visited[27];
int point_count;

void flood_fill(int index,int parent)
{
    if(visited[index]){
        cycle=true;
        return;
    }
    visited[index]=true;
    point_count++;
    for(int i=0;i<connections[index].size();i++)if(connections[index][i]!=parent)flood_fill(connections[index][i],index);
    return;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        for(int i=1;i<=26;i++)connections[i].clear();
        memset(visited,false,sizeof(visited));

        string text;
        cin>>text;
        while(text[0]!='*'){
            connections[text[1]-'A'+1].push_back(text[3]-'A'+1);
            connections[text[3]-'A'+1].push_back(text[1]-'A'+1);

            cin>>text;
        }
        int acorns=0,trees=0;

        cin>>text;
        for(int i=0;i<text.length();i++)if(text[i]>='A' && text[i]<='Z')if(!visited[text[i]-'A'+1]){
            point_count=0;
            cycle=false;
            flood_fill(text[i]-'A'+1,0);
            if(point_count==1)acorns++;
            else if(!cycle)trees++;
        }
        printf("There are %d tree(s) and %d acorn(s).\n",trees,acorns);
    }
}
