#include<bits/stdc++.h>
using namespace std;

vector<int>connections[100001];
int V,E;
int vis[100001],level[100001];

char names[101];

struct Edge
{
    int from,to;
    int cap;
    int rev,flo;
} edges[100001];

void AddEdge(int A,int B,int C)
{
    E++;
    connections[A].push_back(E);
    connections[B].push_back(E);

    edges[E].from=A;
    edges[E].to=B;
    edges[E].cap=C;
    edges[E].flo=0;
    edges[E].rev=C;

    return;
}

bool bfs(int s,int t)
{
    for(int i=1;i<=V;i++)level[i]=-1;

    level[s]=0;
    queue<int>q;
    q.push(s);

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int i=0;i<connections[cur].size();i++){
            Edge e = edges[connections[cur][i]];
            int flow = (cur == e.from? e.flo : e.rev);
            int dest = (cur == e.from? e.to : e.from);

            if(level[dest]==-1 && flow<e.cap){
                level[dest]=level[cur]+1;
                q.push(dest);
            }
        }
    }

    return (level[t]>0);
}

int MaxFlow(int u,int neck,int t)
{
    if(u==t)return neck;

    for(;vis[u]<connections[u].size();vis[u]++){
        Edge &e = edges[connections[u][vis[u]]];
        int &real_flow = (u == e.from ? e.flo : e.rev);
        int &real_rev = (u == e.from ? e.rev : e.flo);
        int dest = (u== e.from ? e.to : e.from);

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

int main()
{
    vector<string>jobs;
    string job;
    while(getline(cin,job)){
        jobs.clear();
        jobs.push_back(job);
        while(getline(cin,job)){
            if(job=="")break;
            jobs.push_back(job);
        }

        V=12;E=0;
        for(int i=3;i<=12;i++)AddEdge(i,2,1);

        int total_app=0;

        for(int i=0;i<jobs.size();i++){
            V++;
            istringstream iss(jobs[i]);
            string temp;

            iss>>temp;
            names[V]=temp[0];
            AddEdge(1,V,temp[1]-'0');
            total_app+=(temp[1]-'0');

            iss>>temp;
            for(int j=0;j<temp.size()-1;j++)AddEdge(V,temp[j]-'0'+3,1);
        }

        int max_flow=Dinic(1,2);
        if(max_flow<total_app)cout<<"!\n";
        else{
            for(int i=3;i<=12;i++){
                bool found=false;
                for(int j=0;j<connections[i].size();j++){
                    Edge e = edges[connections[i][j]];

                    if(e.flo==1 && e.to==i){
                        cout<<names[e.from];
                        found=true;
                    }
                }
                if(!found)cout<<'_';
            }
            cout<<'\n';
        }

        for(int i=1;i<=V;i++)connections[i].clear();
    }
}
