#include<bits/stdc++.h>
using namespace std;

vector<pair<int,double> >connections[101];
double base[101][101],temp[101][101],temp2[101][101];
double sum[101];
int N;

void build(int t)
{
    if(t==1){
        for(int y=1;y<=N;y++)for(int x=1;x<=N;x++)temp[y][x]=base[y][x];
        return;
    }

    build(t/2);
    memset(temp2,0,sizeof(temp2));
    for(int y=1;y<=N;y++)for(int x=1;x<=N;x++)
        for(int k=1;k<=N;k++)temp2[y][x]+=(temp[y][k]*temp[k][x]);

    for(int y=1;y<=N;y++)for(int x=1;x<=N;x++)temp[y][x]=temp2[y][x];

    if(t%2==1){
        memset(temp2,0,sizeof(temp2));
        for(int y=1;y<=N;y++)for(int x=1;x<=N;x++)
            for(int k=1;k<=N;k++)temp2[y][x]+=(temp[y][k]*base[k][x]);
        for(int y=1;y<=N;y++)for(int x=1;x<=N;x++)temp[y][x]=temp2[y][x];
    }

    return;
}

int most_prob(int s)
{
    int biggest=-1;
    for(int y=1;y<=N;y++)if(biggest==-1 || temp[y][s]>temp[biggest][s])biggest=y;
    if(temp[biggest][s]<1e-7)return -1;
    return biggest;
}

int main()
{
    int C;
    scanf("%d",&C);
    for(int c=1;c<=C;c++){
        printf("Scenario #%d:\n",c);
        int M;
        scanf("%d %d",&N,&M);
        for(int i=1;i<=M;i++){
            int A,B,j,s;
            scanf("%d %d %d %d",&A,&B,&j,&s);
            A++;B++;
            connections[A].push_back(make_pair(B,(double)j/s));
            connections[B].push_back(make_pair(A,(double)j/s));
            sum[A]+=((double)j/s);
            sum[B]+=((double)j/s);
        }
        for(int i=1;i<=N;i++){
            for(int o=0;o<connections[i].size();o++){
                int to=connections[i][o].first;
                double prob=connections[i][o].second/sum[i];
                base[to][i]=prob;
            }
        }

        int T;
        scanf("%d",&T);
        for(int test=1;test<=T;test++){
            int t,Q;
            scanf("%d %d",&t,&Q);
            build(t);
            for(int q=1;q<=Q;q++){
                if(q>1)printf(" ");
                int start;
                scanf("%d",&start);
                start++;
                int ans=most_prob(start);
                if(ans==-1)printf("-1");
                else printf("%d",ans-1);
            }
            printf("\n");
        }
        printf("\n");

        for(int i=1;i<=N;i++)connections[i].clear();
        memset(base,0,sizeof(base));
        memset(sum,0,sizeof(sum));
    }
}

