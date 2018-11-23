#include<bits/stdc++.h>
#define LL long long int
using namespace std;

pair<int,int>coordinates[1001];
int adjacency[1001][1001];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >travelling;
bool visited[1001];
int shortest[1001];

int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        int N,P;
        scanf("%d %d",&N,&P);
        for(int i=1;i<=N;i++)scanf("%d %d",&coordinates[i].first,&coordinates[i].second);

        for(int i=1;i<=N;i++)for(int o=i+1;o<=N;o++){
            int x=coordinates[i].first-coordinates[o].first;
            int y=coordinates[i].second-coordinates[o].second;
            adjacency[i][o]=x*x+y*y;
            adjacency[o][i]=x*x+y*y;
        }

        memset(visited,false,sizeof(visited));
        visited[1]=true;

        LL minimum=0;
        for(int i=2;i<=N;i++)shortest[i]=adjacency[1][i];
        for(int i=1;i<N;i++){
            int u=-1;
            for(int o=1;o<=N;o++){
                if(visited[o])continue;
                if(u==-1)u=o;
                else if(shortest[o]<shortest[u])u=o;
            }
            visited[u]=true;
            minimum+=ceil(sqrt((double)shortest[u])*P);
            for(int o=1;o<=N;o++){
                if(!visited[o])shortest[o]=min(shortest[o],adjacency[u][o]);
            }
        }

        printf("Scenario #%d: %lld\n",test,minimum);
    }
}
