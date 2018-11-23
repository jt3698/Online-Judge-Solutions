#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node* left,*right;

    node(){}
    node(node* l,node* r,int v){
        val=v;
        left=l;
        right=r;
    }
};

int numbers[100001];
node* version[100001];

void build(node* cur,int l,int r)
{
    if(l==r){
        cur->val=numbers[l];
        return;
    }

    node* le=new node(NULL,NULL,0);
    node* ri=new node(NULL,NULL,0);
    cur->left=le;
    cur->right=ri;
    build(le,l,(l+r)/2);
    build(ri,(l+r)/2+1,r);
    cur->val=le->val+ri->val;
}

void update(node* prev, node* cur,int l,int r,int x,int v)
{
    if(l==r){
        cur->val=prev->val+v;
        return;
    }

    int mid=(l+r)/2;
    if(x<=mid){
        cur->right=prev->right;
        cur->left=new node(NULL,NULL,0);
        update(prev->left,cur->left,l,mid,x,v);
    }
    else{
        cur->left=prev->left;
        cur->right=new node(NULL,NULL,0);
        update(prev->right,cur->right,mid+1,r,x,v);
    }
    cur->val=cur->right->val+cur->left->val;
    return;
}

int query(node* cur,int l,int r,int lx,int rx)
{
    if(l==lx && r==rx)return cur->val;

    int res=0;
    if(lx<=(l+r)/2)res+=query(cur->left,l,(l+r)/2,lx,min(rx,(l+r)/2));
    if(rx>=(l+r)/2+1)res+=query(cur->right,(l+r)/2+1,r,max(lx,(l+r)/2+1),rx);
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&numbers[i]);

    version[0]=new node(NULL,NULL,0);
    build(version[0],1,n);
    int counter=0;

    int Q;
    scanf("%d",&Q);
    for(int q=1;q<=Q;q++){
        int type;
        scanf("%d",&type);
        if(type==1){
            counter++;
            version[counter]=new node(NULL,NULL,0);
            int idx,pos,v;
            scanf("%d %d %d",&idx,&pos,&v);
            update(version[idx],version[counter],1,n,pos,v);
        }
        else{
            int idx,l,r;
            scanf("%d %d %d",&idx,&l,&r);
            printf("%d\n",query(version[idx],1,n,l,r));
        }
    }
}
