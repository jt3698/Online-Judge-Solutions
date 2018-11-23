#include<bits/stdc++.h>
using namespace std;

int fenwick[1000001];
int W;

void update(int x,int add)
{
    x++;
    while(x<=W){
        fenwick[x]+=add;
        x+=x&(-x);
    }
    return;
}

int query(int x)
{
    x++;
    int sum=0;
    while(x>0){
        sum+=fenwick[x];
        x-=x&(-x);
    }
    return sum;
}

int main()
{
    int N,Q;
    scanf("%d %d %d",&N,&Q,&W);
    for(int i=1;i<=N;i++){
        int A,B;
        scanf("%d %d",&A,&B);
        update(A,1);
        update(B+1,-1);
    }
    for(int i=1;i<=Q;i++){
        int A;
        scanf("%d",&A);
        printf("%d\n",query(A));
    }
}
