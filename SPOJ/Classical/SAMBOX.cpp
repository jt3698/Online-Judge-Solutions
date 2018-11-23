#include<bits/stdc++.h>
#define LL long long
using namespace std;

int index_now[200001];
set<int>direct_boxes[200001];
LL seg_tree[8000001];
vector<int>inside[200001];
int pos[200001],until[200001];
int where_am_i[200001];
int counter;

void process(int x)
{
    counter++;
    pos[x]=counter;
    for(int i=0;i<inside[x].size();i++)process(inside[x][i]);
    until[x]=counter;
    return;
}

void update(int n,int l,int r,int x,LL add)
{
    if(l==r){
        seg_tree[n]+=add;
        return;
    }

    if(x<=(l+r)/2)update(n*2,l,(l+r)/2,x,add);
    else update(n*2+1,(l+r)/2+1,r,x,add);
    seg_tree[n]=seg_tree[n*2]+seg_tree[n*2+1];
    return;
}

LL query(int n,int l,int r,int lx,int rx)
{
    if(l==lx && r==rx)return seg_tree[n];

    LL res=0;
    if(lx<=(l+r)/2)res+=query(n*2,l,(l+r)/2,lx,min(rx,(l+r)/2));
    if(rx>=(l+r)/2+1)res+=query(n*2+1,(l+r)/2+1,r,max(lx,(l+r)/2+1),rx);
    return res;
}

void convert(int A,int B)
{
    swap(index_now[A],index_now[B]);

    if(where_am_i[A]!=0)direct_boxes[where_am_i[A]].erase(A);
    if(where_am_i[B]!=0)direct_boxes[where_am_i[B]].erase(B);

    if(where_am_i[A]!=0)direct_boxes[where_am_i[A]].insert(B);
    if(where_am_i[B]!=0)direct_boxes[where_am_i[B]].insert(A);

    swap(where_am_i[A],where_am_i[B]);
    return;
}

int smallest_inside(int x)
{
    return *(direct_boxes[x].begin());
}

int main()
{
    int N,Q;
    scanf("%d %d",&N,&Q);
    for(int i=2;i<=N;i++){
        int A;
        scanf("%d",&A);
        inside[A].push_back(i);
        where_am_i[i]=A;
        direct_boxes[A].insert(i);
    }
    process(1);
    for(int i=1;i<=N;i++)index_now[i]=i;

    for(int q=1;q<=Q;q++){
        int type;
        scanf("%d",&type);
        if(type==1){
            int y;
            LL x;
            scanf("%lld %d",&x,&y);
            update(1,1,N,pos[index_now[y]],x);
        }
        else if(type==2){
            int x,y;
            scanf("%d %d",&x,&y);
            convert(x,y);
        }
        else if(type==3){
            int x;
            scanf("%d",&x);
            printf("%lld\n",query(1,1,N,pos[index_now[x]],until[index_now[x]]));
        }
        else{
            int x;
            scanf("%d",&x);
            if(direct_boxes[index_now[x]].empty())printf("-1\n");
            else{
                x=smallest_inside(index_now[x]);
                printf("%lld\n",query(1,1,N,pos[index_now[x]],until[index_now[x]]));
            }
        }
    }
}

