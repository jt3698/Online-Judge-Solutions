#include<bits/stdc++.h>
using namespace std;

pair<int,int>numbers[100001];
int act_order[100001],address[100001];
int A[100001];

struct node
{
    int val;
    node* left,*right;
    node(){}
    node(node* l,node* r,int v){
        left=l;
        right=r;
        val=v;
    }
};

node* version[100001];

void build(node* cur,int l,int r)
{
    if(l==r){
        cur->val=0;
        return;
    }

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
    cur->val=cur->left->val+cur->right->val;
    return;
}

int query(node* I,node* J,int l,int r,int x)
{
    if(l==r)return l;

    int to_the_left=J->left->val-I->left->val;
    if(x<=to_the_left)return query(I->left,J->left,l,(l+r)/2,x);
    return query(I->right,J->right,(l+r)/2+1,r,x-to_the_left);
}

int main()
{
    int N,Q;
    scanf("%d %d",&N,&Q);
    for(int i=1;i<=N;i++){
        scanf("%d",&A[i]);
        numbers[i]=make_pair(A[i],i);
    }
    sort(numbers+1,numbers+1+N);
    for(int i=1;i<=N;i++){
        address[numbers[i].second]=i;
        act_order[i]=numbers[i].second;
    }

    version[0]=new node(NULL,NULL,0);
    build(version[0],1,N);
    for(int i=1;i<=N;i++){
        version[i]=new node(NULL,NULL,0);
        update(version[i-1],version[i],1,N,address[i]);
    }

    for(int q=1;q<=Q;q++){
        int i,j,k;
        scanf("%d %d %d",&i,&j,&k);
        printf("%d\n",A[act_order[query(version[i-1],version[j],1,N,k)]]);
    }
}
