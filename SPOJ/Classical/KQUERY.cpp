#include<bits/stdc++.h>
using namespace std;

int sequence[30001],sequence_order[30001],queries_order[200001],queries_res[200001];
pair<int,pair<int,int> >queries[200001];
int seg_tree[120001];

bool cmp(int A,int B)
{
    return sequence[A]<sequence[B];
}

bool cmp2(int A,int B)
{
    return queries[A].first<queries[B].first;
}

void build_seg_tree(int index,int left,int right)
{
    if(left==right){
        seg_tree[index]=1;
        return;
    }

    build_seg_tree(index*2,left,(left+right)/2);
    build_seg_tree(index*2+1,(left+right)/2+1,right);

    seg_tree[index]=seg_tree[index*2]+seg_tree[index*2+1];

    return;
}

void turn_off(int index,int left,int right,int target)
{
    if(left==right){
        seg_tree[index]=0;
        return;
    }

    if(target<=(left+right)/2)turn_off(index*2,left,(left+right)/2,target);
    else turn_off(index*2+1,(left+right)/2+1,right,target);

    seg_tree[index]=seg_tree[index*2]+seg_tree[index*2+1];

    return;
}

int query(int index,int left,int right,int A,int B)
{
    if(left==A && right==B)return seg_tree[index];

    int a=0,b=0;
    if(A<=(left+right)/2)a=query(index*2,left,(left+right)/2,A,min(B,(left+right)/2));
    if(B>=(left+right)/2+1)b=query(index*2+1,(left+right)/2+1,right,max(A,(left+right)/2+1),B);

    return a+b;
}

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&sequence[i]);
        sequence_order[i]=i;
    }
    sort(sequence_order+1,sequence_order+N+1,cmp);

    int Q;
    scanf("%d",&Q);
    for(int q=1;q<=Q;q++){
        scanf("%d %d %d",&queries[q].second.first,&queries[q].second.second,&queries[q].first);
        queries_order[q]=q;
    }
    sort(queries_order+1,queries_order+Q+1,cmp2);

    build_seg_tree(1,1,N);

    int index_check=1;
    for(int q=1;q<=Q;q++){
        while(index_check<=N){
            if(sequence[sequence_order[index_check]]<=queries[queries_order[q]].first){
                turn_off(1,1,N,sequence_order[index_check]);
                index_check++;
            }
            else break;
        }

        queries_res[queries_order[q]]=query(1,1,N,queries[queries_order[q]].second.first,queries[queries_order[q]].second.second);
    }

    for(int q=1;q<=Q;q++)printf("%d\n",queries_res[q]);

    return 0;
}
