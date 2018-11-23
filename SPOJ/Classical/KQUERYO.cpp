#include<bits/stdc++.h>
using namespace std;

vector<int>seg_tree[120001];
int sequence[30001];
int last_answer;

void build_seg_tree(int index,int left,int right)
{
    if(left==right){
        seg_tree[index].push_back(sequence[left]);
        return;
    }

    build_seg_tree(index*2,left,(left+right)/2);
    build_seg_tree(index*2+1,(left+right)/2+1,right);

    merge(seg_tree[index*2].begin(),seg_tree[index*2].end(),seg_tree[index*2+1].begin(),seg_tree[index*2+1].end(),back_inserter(seg_tree[index]));

    return;
}

int query(int index,int left,int right,int A,int B,int K)
{
    if(left==A && right==B){
        return seg_tree[index].begin()+seg_tree[index].size()-upper_bound(seg_tree[index].begin(),seg_tree[index].end(),K);
    }

    int ans=0;
    if(A<=(left+right)/2)ans+=query(index*2,left,(left+right)/2,A,min(B,(left+right)/2),K);
    if(B>=(left+right)/2+1)ans+=query(index*2+1,(left+right)/2+1,right,max(A,(left+right)/2+1),B,K);

    return ans;
}

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)scanf("%d",&sequence[i]);

    build_seg_tree(1,1,N);

    int Q;
    scanf("%d",&Q);
    for(int q=1;q<=Q;q++){
        int A,B,C;
        scanf("%d %d %d",&A,&B,&C);
        A=A^last_answer;
        B=B^last_answer;
        C=C^last_answer;
        A=max(1,A);
        B=min(N,B);
        if(B>=A)printf("%d\n",last_answer=query(1,1,N,A,B,C));
        else{
            printf("0\n");
            last_answer=0;
        }
    }

    return 0;
}
