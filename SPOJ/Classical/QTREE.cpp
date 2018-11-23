#include<bits/stdc++.h>
using namespace std;

int chain_heads[10001],no_of_chains,no_of_edges;

struct treeNode
{
    int depth;
    int subtree_size;
    int pos_segbase;
    int chain;
    int sparse[15];
    pair<int,int>best;
    vector<pair<int,int> >connections;
} node[10001];

struct Edge
{
    int weight;
    int deeper_end;
} edge[10001];

struct segmentTree
{
    int base_array[10001],tree[40001];
} s;

void dfs(int curr,int prev,int dep)
{
    node[curr].sparse[1]=prev;
    for(int i=2;i<=14 && node[curr].sparse[i-1]!=-1;i++)
        node[curr].sparse[i]=node[node[curr].sparse[i-1]].sparse[i-1];
    node[curr].depth=dep;
    node[curr].subtree_size=1;

    for(int i=0;i<node[curr].connections.size();i++){
        pair<int,int>j=node[curr].connections[i];
        if(j.first!=prev){
            dfs(j.first,curr,dep+1);
            node[curr].subtree_size+=node[j.first].subtree_size;
            if(node[j.first].subtree_size>node[curr].best.second)node[curr].best=make_pair(i,node[j.first].subtree_size);
            edge[j.second].deeper_end=j.first;
        }
    }
    return;
}

void hld(int curr,int id,int curr_chain)
{
    if(chain_heads[curr_chain]==-1)chain_heads[curr_chain]=curr;
    node[curr].chain=curr_chain;

    node[curr].pos_segbase=++no_of_edges;
    if(id!=-1)s.base_array[no_of_edges]=edge[id].weight;

    if(node[curr].best.first!=-1){
        pair<int,int>j=node[curr].connections[node[curr].best.first];
        hld(j.first,j.second,curr_chain);
        for(int i=0;i<node[curr].connections.size();i++)if(node[curr].connections[i].first!=node[curr].sparse[1] && i!=node[curr].best.first)
            hld(node[curr].connections[i].first,node[curr].connections[i].second,++no_of_chains);
    }
    return;
}

void build_seg_tree(int n,int l,int r)
{
    if (l==r){
        s.tree[n]=s.base_array[l];
        return;
    }

    build_seg_tree(n*2,l,(l+r)/2);
    build_seg_tree(n*2+1,(l+r)/2+1,r);
    s.tree[n]= max(s.tree[n*2],s.tree[n*2+1]);
    return;
}

void update(int n,int l,int r,int x,int val)
{
    if(l==x && r==x){
        s.tree[n]=val;
        return;
    }

    if(x<=(l+r)/2)update(n*2,l,(l+r)/2,x,val);
    else update(n*2+1,(l+r)/2+1,r,x,val);
    s.tree[n]=max(s.tree[n*2],s.tree[n*2+1]);
    return;
}

int RMQ(int n,int l,int r,int A,int B)
{
    if (A==l && B==r)return s.tree[n];

    int ans=0;
    if(A<=(l+r)/2)ans=max(ans,RMQ(n*2,l,(l+r)/2,A,min(B,(l+r)/2)));
    if(B>=(l+r)/2+1)ans=max(ans,RMQ(n*2+1,(l+r)/2+1,r,max(A,(l+r)/2+1),B));
    return ans;
}

int query(int A,int L)
{
    int ans=0;
    while(node[A].chain!=node[L].chain){
        ans=max(ans,RMQ(1,1,no_of_edges,node[chain_heads[node[A].chain]].pos_segbase,node[A].pos_segbase));
        A=node[chain_heads[node[A].chain]].sparse[1];
    }
    if(A!=L)ans=max(ans,RMQ(1,1,no_of_edges,node[L].pos_segbase+1,node[A].pos_segbase));
    return ans;
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

int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        int N;
        scanf("%d",&N);

        no_of_chains=1;no_of_edges=-1;
        memset(chain_heads,-1,sizeof(chain_heads));
        for(int i=1;i<=N;i++){
            node[i].connections.clear();
            memset(node[i].sparse,-1,sizeof(node[i].sparse));
            node[i].best=make_pair(-1,0);
        }

        for(int i=1;i<N;i++){
            int A,B,C;
            scanf("%d %d %d",&A,&B,&C);
            node[A].connections.push_back(make_pair(B,i));
            node[B].connections.push_back(make_pair(A,i));
            edge[i].weight=C;
        }

        dfs(1,-1,1);
        hld(1,-1,1);
        build_seg_tree(1,1,no_of_edges);

        char order[10];
        int counter=0;
        while(getchar()!='\n');
        order[counter]=getchar();
        while(order[counter]!=' ' && order[counter]!='\n')order[++counter]=getchar();

        while(order[0]!='D'){
            int x,y;
            scanf("%d %d",&x,&y);
            if(order[0]=='C')update(1,1,no_of_edges,node[edge[x].deeper_end].pos_segbase,y);
            else{
                int L=lca(x,y);
                printf("%d\n",max(query(x,L),query(y,L)));
            }
            counter=0;
            while(getchar()!='\n');
            order[counter]=getchar();
            while(order[counter]!=' ' && order[counter]!='\n')order[++counter]=getchar();
        }
    }
}
