#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int E,V;
int level[100001],vis[100001];

vector<int>connections[100001];

struct Edge
{
    int flo,rev;
    int from,to;
    int cap;
} edges[100001];

void AddEdge(int A,int B,int C)
{
    if(C>0){
        E++;
        connections[A].push_back(E);
        connections[B].push_back(E);

        edges[E].from=A;
        edges[E].to=B;
        edges[E].flo=0;
        edges[E].rev=C;
        edges[E].cap=C;
    }

    return;
}

int MaxFlow(int u,int neck,int t)
{
    if(u==t)return neck;

    for(;vis[u]<connections[u].size();vis[u]++){
        Edge &e=edges[connections[u][vis[u]]];
        int &real_flow = (e.from == u ? e.flo : e.rev);
        int &real_rev = (e.from == u ? e.rev : e.flo);
        int dest = (e.from == u ? e.to : e.from);

        if(level[dest]==level[u]+1 && real_flow<e.cap){
            int new_neck=min(neck,e.cap-real_flow);
            int temp_flow=MaxFlow(dest,new_neck,t);

            if(temp_flow>0){
                real_flow+=temp_flow;
                real_rev-=temp_flow;

                return temp_flow;
            }
        }
    }

    return 0;
}

bool bfs(int s,int t)
{
    for(int i=1;i<=V;i++)level[i]=-1;

    queue<int>q;
    level[s]=0;
    q.push(s);

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=0;i<connections[u].size();i++){
            Edge e=edges[connections[u][i]];
            int dest = (e.from == u ? e.to : e.from);
            int real_flow = (e.from == u ? e.flo : e.rev);

            if(level[dest]==-1 && real_flow<e.cap){
                level[dest]=level[u]+1;
                q.push(dest);
            }
        }
    }

    return (level[t]>0);
}

int Dinic(int s,int t)
{
    if(s==t)return -1;

    int total=0;
    while(bfs(s,t)){
        for(int i=1;i<=V;i++)vis[i]=0;

        int flow=0;
        do{
            total+=flow;
            flow=MaxFlow(s,INT_MAX,t);
        }while(flow>0);
    }

    return total;
}

map<string,int>plugs;
int how_many[1001],to_plug[1001];
int counter;

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        if(t>1)printf("\n");

        V=2;E=0;
        counter=0;
        plugs.clear();
        memset(how_many,0,sizeof(how_many));
        memset(to_plug,0,sizeof(to_plug));

        int N;

        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            string name;
            cin>>name;

            if(plugs[name]==0)plugs[name]=++counter;
            how_many[plugs[name]]++;
        }

        int devices;
        scanf("%d",&devices);
        for(int i=1;i<=devices;i++){
            string name;
            cin>>name;
            cin>>name;

            if(plugs[name]==0)plugs[name]=++counter;
            to_plug[plugs[name]]++;
        }

        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            string A,B;
            cin>>A>>B;

            if(plugs[A]==0)plugs[A]=++counter;
            if(plugs[B]==0)plugs[B]=++counter;

            AddEdge(plugs[A]+2,plugs[B]+2,INF);
        }

        V=2+counter*2;

        for(int i=1;i<=counter;i++){
            AddEdge(1,2+i,to_plug[i]);
            AddEdge(2+i,2+counter+i,INF);
        }

        for(int i=1;i<=counter;i++)if(how_many[i]>0)
            AddEdge(2+counter+i,2,how_many[i]);

        printf("%d\n",devices-Dinic(1,2));

        for(int i=1;i<=V;i++)connections[i].clear();
    }
}
