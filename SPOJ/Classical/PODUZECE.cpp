#include<bits/stdc++.h>
using namespace std;

vector<int>connections[100001];
int par[100001];
bool intern[100001];
bool vis[100001];
int depth[100001];
int deepest,travel,deep_t;
int intern_counter;
vector<int>subtrees;

void dfs(int x,int t)
{
    vis[x]=true;
    if(t>deep_t){
        deepest=x;
        deep_t=t;
    }
    if(intern[x])travel=max(travel,t-1);
    for(int i=0;i<connections[x].size();i++){
        int nxt=connections[x][i];
        if(!vis[nxt])dfs(nxt,t+1);
    }
    return;
}

void de_flood(int x)
{
    vis[x]=false;
    for(int i=0;i<connections[x].size();i++){
        int nxt=connections[x][i];
        if(vis[nxt])de_flood(nxt);
    }
    return;
}

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=M;i++){
        int A,B;
        scanf("%d %d",&A,&B);
        intern[A]=true;
        par[A]=B;
        connections[A].push_back(B);
        connections[B].push_back(A);
    }

    int maximum_within=-1;
    int counter=0;
    for(int i=1;i<=N;i++)if(!intern[i]){
        deep_t=0;
        dfs(i,1);
        subtrees.push_back(deep_t);
        if(intern[deepest]){
            counter++;
            de_flood(i);
            travel=-1;
            dfs(deepest,0);
            maximum_within=max(maximum_within,travel);
        }
    }

    if(counter==1){
        printf("%d\n",maximum_within);
        return 0;
    }
    sort(subtrees.begin(),subtrees.end());
    if(subtrees.size()==2){
        printf("%d\n",max(maximum_within,subtrees[subtrees.size()-1]+subtrees[subtrees.size()-2]-2));
        return 0;
    }

    if(subtrees.size()==3 && subtrees[0]==subtrees[1] && subtrees[1]==subtrees[2])
        printf("%d\n",max(maximum_within,subtrees[1]*2-1));
    else if(subtrees[subtrees.size()-1]+subtrees[subtrees.size()-2]+(int)subtrees.size()-4>maximum_within)printf("-1\n");
    else printf("%d\n",maximum_within);

    return 0;
}
