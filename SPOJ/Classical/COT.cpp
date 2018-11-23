#include<bits/stdc++.h>
using namespace std;

struct node
{
    node* left,*right;
    int val;

    node(){}
    node(node* l,node* r,int v){
        left=l;
        right=r;
        val=v;
    }
};

int depth[150001];
int sparse[150001][21];
bool vis[150001];
vector<int>connections[150001];
int A[150001];
pair<int,int>numbers[150001];
int act_order[150001],address[150001];
int N,Q;

node* version[150001];

void build(node* cur,int l,int r)
{
    if(l==r)return;

    cur->left=new node(NULL,NULL,0);
    cur->right=new node(NULL,NULL,0);
    build(cur->left,l,(l+r)/2);
    build(cur->right,(l+r)/2+1,r);
    return;
}

void update(node* prev,node* cur,int l,int r,int x)
{
    if(l==r){
        cur->val=1;
        return;
    }

    if(x<=(l+r)/2){
        cur->right=prev->right;
        cur->left=new node(NULL,NULL,0);
        update(prev->left,cur->left,l,(l+r)/2,x);
    }
    else{
        cur->left=prev->left;
        cur->right=new node(NULL,NULL,0);
        update(prev->right,cur->right,(l+r)/2+1,r,x);
    }
    cur->val=cur->right->val+cur->left->val;
    return;
}

int query(node* A,node* B,node* LCA,node* LCAup,int l,int r,int x)
{
    if(l==r)return l;

    int to_the_left=A->left->val+B->left->val-LCA->left->val-LCAup->left->val;
    if(x<=to_the_left)return query(A->left,B->left,LCA->left,LCAup->left,l,(l+r)/2,x);
    return query(A->right,B->right,LCA->right,LCAup->right,(l+r)/2+1,r,x-to_the_left);
}

void dfs(int cur,int d)
{
    vis[cur]=true;
    depth[cur]=d;
    for(int i=2;i<=20 && sparse[cur][i-1]!=0;i++)sparse[cur][i]=sparse[sparse[cur][i-1]][i-1];
    version[cur]=new node(NULL,NULL,0);
    update(version[sparse[cur][1]],version[cur],1,N,act_order[cur]);

    for(int i=0;i<connections[cur].size();i++){
        int nxt=connections[cur][i];
        if(!vis[nxt]){
            sparse[nxt][1]=cur;
            dfs(nxt,d+1);
        }
    }
    return;
}

int lca(int A,int B)
{
    if(depth[A]>depth[B])swap(A,B);
    for(int i=20;i>=1;i--)if(sparse[B][i]!=0){
        if(depth[sparse[B][i]]>=depth[A])B=sparse[B][i];
    }

    if(B==A)return A;
    for(int i=20;i>=1;i--)if(sparse[A][i]!=sparse[B][i]){
        A=sparse[A][i];
        B=sparse[B][i];
    }
    return sparse[A][1];
}

int main()
{
    scanf("%d %d",&N,&Q);
    for(int i=1;i<=N;i++){
        scanf("%d",&A[i]);
        numbers[i]=make_pair(A[i],i);
    }
    sort(numbers+1,numbers+1+N);
    for(int i=1;i<=N;i++){
        address[i]=numbers[i].second;
        act_order[numbers[i].second]=i;
    }

    for(int i=1;i<N;i++){
        int A,B;
        scanf("%d %d",&A,&B);
        connections[A].push_back(B);
        connections[B].push_back(A);
    }

    version[0]=new node(NULL,NULL,0);
    build(version[0],1,N);
    dfs(1,1);

    for(int q=1;q<=Q;q++){
        int u,v,k;
        scanf("%d %d %d",&u,&v,&k);
        printf("%d\n",A[address[query(version[u],version[v],version[lca(u,v)],version[sparse[lca(u,v)][1]],1,N,k)]]);
    }
}
