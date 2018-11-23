#include<bits/stdc++.h>
#define LL long long int
using namespace std;

int exp_2[100];

struct treeNode
{
    vector<pair<int,int> >connections;
    int depth;
    int sparse[15];
    LL dist[15];
} node[10001];

struct Edge
{
    LL weight;
}edge[10001];

void dfs(int curr,int par,int dep)
{
    node[curr].depth=dep;
    node[curr].sparse[1]=par;
    for(int i=2;i<=14;i++)if(node[curr].sparse[i-1]!=-1){
        node[curr].sparse[i]=node[node[curr].sparse[i-1]].sparse[i-1];
        node[curr].dist[i]=node[node[curr].sparse[i-1]].dist[i-1]+node[curr].dist[i-1];
    }
    for(int i=0;i<node[curr].connections.size();i++){
        pair<int,int>j=node[curr].connections[i];
        if(j.first!=par){
            node[j.first].dist[1]=edge[j.second].weight;
            dfs(j.first,curr,dep+1);
        }
    }
    return;
}

int lca(int A,int B)
{
    if(node[A].depth>node[B].depth)swap(A,B);

    for(int i=14;i>=1;i--)if(node[B].sparse[i]!=-1)
        if(node[node[B].sparse[i]].depth>=node[A].depth)B=node[B].sparse[i];

    if(A==B)return A;

    for(int i=14;i>=1;i--)if(node[A].sparse[i]!=node[B].sparse[i]){
        A=node[A].sparse[i];
        B=node[B].sparse[i];
    }
    return node[A].sparse[1];
}

LL query_dist(int A,int B)
{
    if(node[A].depth>node[B].depth)swap(A,B);

    LL res=0;
    for(int i=14;i>=1;i--)if(node[B].sparse[i]!=-1)
        if(node[node[B].sparse[i]].depth>=node[A].depth){
            res+=node[B].dist[i];
            B=node[B].sparse[i];
        }

    if(A==B)return res;

    for(int i=14;i>=1;i--)if(node[A].sparse[i]!=node[B].sparse[i]){
        res+=node[A].dist[i];
        res+=node[B].dist[i];
        A=node[A].sparse[i];
        B=node[B].sparse[i];
    }
    return res+node[A].dist[1]+node[B].dist[1];
}

int crawl(int A,int K)
{
    K--;
    for(int i=14;i>=1;i--)if(K>=exp_2[i-1]){
        K-=exp_2[i-1];
        A=node[A].sparse[i];
    }
    return A;
}

int find_dist(int A,int B)
{
    int res=1;
    for(int i=14;i>=1;i--)if(node[A].sparse[i]!=-1)
        if(node[node[A].sparse[i]].depth>=node[B].depth){
            res+=exp_2[i-1];
            A=node[A].sparse[i];
    }
    return res;
}

int query_k(int A,int B,int k)
{
    int L=lca(A,B);
    if(find_dist(A,L)>=k)return crawl(A,k);
    return crawl(B,find_dist(B,L)-k+find_dist(A,L));
}

int main()
{
    exp_2[0]=1;
    for(int i=1;i<=30;i++)exp_2[i]=exp_2[i-1]*2;

    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        int N;
        scanf("%d",&N);

        for(int i=1;i<=N;i++){
            node[i].connections.clear();
            memset(node[i].sparse,-1,sizeof(node[i].sparse));
        }

        for(int i=1;i<N;i++){
            int A,B;
            LL C;
            scanf("%d %d %lld",&A,&B,&C);
            node[A].connections.push_back(make_pair(B,i));
            node[B].connections.push_back(make_pair(A,i));
            edge[i].weight=C;
        }

        dfs(1,-1,1);

        char order[10];
        int counter=0;
        while(getchar()!='\n');
        order[counter]=getchar();
        while(order[counter]!=' ' && order[counter]!='\n')order[++counter]=getchar();

        while(order[1]!='O'){
            int x,y;
            scanf("%d %d",&x,&y);
            if(order[0]=='K'){
                int k;
                scanf("%d",&k);
                printf("%d\n",query_k(x,y,k));
            }
            else printf("%lld\n",query_dist(x,y));

            counter=0;
            while(getchar()!='\n');
            order[counter]=getchar();
            while(order[counter]!=' ' && order[counter]!='\n')order[++counter]=getchar();
        }
    }
}
