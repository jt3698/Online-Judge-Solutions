#include<bits/stdc++.h>
using namespace std;

int seg_tree[320001],lazy[320001];
map<int,bool>check;
map<int,int>compress;
vector<int>values;
vector<pair<int,int> >stored_posters;

void update(int index,int left,int right,int A,int B,int x)
{
    if(A==left && B==right){
        if(left==right){
            lazy[index]=-1;
            seg_tree[index]=x;
        }
        else{
            lazy[index]=-1;
            lazy[index*2]=x;
            lazy[index*2+1]=x;
            seg_tree[index]=x;
        }
        return;
    }
    if(lazy[index]!=-1){
        lazy[index*2]=lazy[index];
        lazy[index*2+1]=lazy[index];
        lazy[index]=-1;
    }
    if(A<=(left+right)/2)update(index*2,left,(left+right)/2,A,min(B,(left+right)/2),x);
    if(B>=(left+right)/2+1)update(index*2+1,(left+right)/2+1,right,max(A,(left+right)/2+1),B,x);

    return;
}

int query(int index,int left,int right,int target)
{
    if(left==right){
        if(lazy[index]!=-1)seg_tree[index]=lazy[index];
        return seg_tree[index];
    }
    if(lazy[index]!=-1){
        lazy[index*2]=lazy[index];
        lazy[index*2+1]=lazy[index];
        lazy[index]=-1;
    }
    if(target<=(left+right)/2)return query(index*2,left,(left+right)/2,target);
    return query(index*2+1,(left+right)/2+1,right,target);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        memset(lazy,-1,sizeof(lazy));
        compress.clear();
        values.clear();
        stored_posters.clear();
        check.clear();

        int N;
        scanf("%d",&N);

        for(int i=1;i<=N;i++){
            int A,B;
            scanf("%d %d",&A,&B);
            values.push_back(A);
            values.push_back(B);
            stored_posters.push_back(make_pair(A,B));
        }

        int value_count=0;
        sort(values.begin(),values.end());
        for(int i=0;i<values.size();i++)
            if(compress[values[i]]==0)compress[values[i]]=++value_count;

        for(int i=0;i<stored_posters.size();i++){
            int A=compress[stored_posters[i].first];
            int B=compress[stored_posters[i].second];
            update(1,1,value_count,A,B,i);
        }

        int counter=0;
        for(int i=1;i<=value_count;i++){
            int poster=query(1,1,value_count,i);
            if(!check[poster]){
                check[poster]=true;
                counter++;
            }
        }
        printf("%d\n",counter);
    }
    return 0;
}
