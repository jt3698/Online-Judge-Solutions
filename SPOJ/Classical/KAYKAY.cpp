#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL BIG=10e11;
LL SMALL=-(10e11);

LL value[201];
int LCRS[201][2];
vector<int>connections[201],realcon[201];
bool vis[201];
int k1,k2;

bool vis1[201][201][2],vis2[201][201],vis3[201],vis4[201],vis5[201];
LL dp1[201][201][2],dp2[201][201];
LL dp3[201],dp4[201];
LL dp5[201];
int subtree[201];

LL DP2(int x,int k)
{
    if(vis2[x][k])return dp2[x][k];
    vis2[x][k]=true;

    if(k==0)return dp2[x][k]=0;
    if(x==0)return dp2[x][k]=BIG;

    if(k==k2)return dp2[x][k]=value[x]+DP2(LCRS[x][0],k-1);

    LL res=DP2(LCRS[x][1],k);
    for(int i=min(k-1,subtree[LCRS[x][0]]);i>=0 && k-1-i<=subtree[LCRS[x][1]];i--)
        res=min(res,value[x]+DP2(LCRS[x][0],i)+DP2(LCRS[x][1],k-1-i));
    return dp2[x][k]=res;
}

LL DP4(int x)
{
    if(vis4[x])return dp4[x];
    vis4[x]=true;

    LL res=BIG;
    res=min(res,DP2(x,k2));
    for(int i=0;i<realcon[x].size();i++)res=min(res,DP4(realcon[x][i]));
    return dp4[x]=res;
}

LL DP1(int x,int k,int need_other)
{
    if(vis1[x][k][need_other])return dp1[x][k][need_other];
    vis1[x][k][need_other]=true;

    if(need_other==0){
        if(k==0)return dp1[x][k][need_other]=0;
        if(x==0)return dp1[x][k][need_other]=SMALL;

        if(k==k1)return dp1[x][k][need_other]=value[x]+DP1(LCRS[x][0],k-1,need_other);

        LL res=DP1(LCRS[x][1],k,need_other);
        for(int i=min(k-1,subtree[LCRS[x][0]]);i>=0 && k-1-i<=subtree[LCRS[x][1]];i--)
            res=max(res,value[x]+DP1(LCRS[x][0],i,need_other)+DP1(LCRS[x][1],k-1-i,need_other));
        return dp1[x][k][need_other]=res;
    }
    else{
        if(k==0)return dp1[x][k][need_other]=(-1)*DP4(x);
        if(x==0)return dp1[x][k][need_other]=SMALL;

        if(k==k1)return dp1[x][k][need_other]=value[x]+DP1(LCRS[x][0],k-1,need_other);

        LL res=DP1(LCRS[x][1],k,need_other);
        res=max(res,DP1(LCRS[x][1],k,0)-DP4(x));
        for(int i=min(k-1,subtree[LCRS[x][0]]);i>=0 && k-1-i<=subtree[LCRS[x][1]];i--){
            res=max(res,value[x]+DP1(LCRS[x][0],i,0)+DP1(LCRS[x][1],k-1-i,1));
            res=max(res,value[x]+DP1(LCRS[x][0],i,1)+DP1(LCRS[x][1],k-1-i,0));
        }
        return dp1[x][k][need_other]=res;
    }
}

LL DP3(int x)
{
    if(vis3[x])return dp3[x];
    vis3[x]=true;

    LL res=SMALL;
    res=max(res,DP1(x,k1,0));
    for(int i=0;i<realcon[x].size();i++)res=max(res,DP3(realcon[x][i]));
    return dp3[x]=res;
}

LL DP5(int x)
{
    if(vis5[x])return dp5[x];
    vis5[x]=true;

    LL res=SMALL;
    ///FINISH NOW
    res=max(res,DP1(x,k1,1));

    int biggest=-1;
    int smallest=-1;

    for(int i=0;i<realcon[x].size();i++){
        DP3(realcon[x][i]);
        DP4(realcon[x][i]);
        if(biggest==-1 || dp3[realcon[x][i]]>dp3[biggest])biggest=realcon[x][i];
        if(smallest==-1 || dp4[realcon[x][i]]<=dp4[smallest])smallest=realcon[x][i];
    }
    if(biggest!=smallest)res=max(res,dp3[biggest]-dp4[smallest]);

    ///GIVE TO SOMEONE
    for(int i=0;i<realcon[x].size();i++)res=max(res,DP5(realcon[x][i]));

    return res;
}

void dfs(int x)
{
    vis[x]=true;
    for(int i=0;i<connections[x].size();i++){
        int nxt=connections[x][i];
        if(!vis[nxt]){
            realcon[x].push_back(nxt);
            dfs(nxt);
        }
    }
    return;
}

void dfs2(int x)
{
    if(x==0)return;
    dfs2(LCRS[x][0]);
    dfs2(LCRS[x][1]);
    subtree[x]=1+subtree[LCRS[x][0]]+subtree[LCRS[x][1]];
    return;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        int N;
        scanf("%d %d %d",&N,&k1,&k2);
        for(int i=1;i<=N;i++)scanf("%lld",&value[i]);

        for(int i=1;i<N;i++){
            int A,B;
            scanf("%d %d",&A,&B);
            A++;B++;
            connections[A].push_back(B);
            connections[B].push_back(A);
        }

        memset(vis,false,sizeof(vis));
        dfs(1);
        for(int i=1;i<=N;i++){
            if(realcon[i].size()>=1)LCRS[i][0]=realcon[i][0];
            for(int o=1;o<realcon[i].size();o++)LCRS[realcon[i][o-1]][1]=realcon[i][o];
        }
        dfs2(1);

        /*cout<<endl;
        for(int i=1;i<=N;i++){
            cout<<i<<" : ";
            for(int o=0;o<realcon[i].size();o++)cout<<realcon[i][o]<<" ";
            cout<<endl;
        }
        cout<<endl;
        for(int i=1;i<=N;i++)cout<<i<<" : "<<LCRS[i][0]<<" "<<LCRS[i][1]<<endl;
        cout<<endl;*/

        LL ans=DP5(1);
        for(int i=1;i<=N;i++)value[i]*=(-1);
        memset(vis1,false,sizeof(vis1));
        memset(vis2,false,sizeof(vis2));
        memset(vis3,false,sizeof(vis3));
        memset(vis4,false,sizeof(vis4));
        memset(vis5,false,sizeof(vis5));
        swap(k1,k2);
        ans=max(ans,DP5(1));
        if(ans<-(10e9) || ans>10e9)printf("-1\n");
        else printf("%lld\n",ans);

        memset(vis1,false,sizeof(vis1));
        memset(vis2,false,sizeof(vis2));
        memset(vis3,false,sizeof(vis3));
        memset(vis4,false,sizeof(vis4));
        memset(vis5,false,sizeof(vis5));
        for(int i=1;i<=N;i++){
            connections[i].clear();
            realcon[i].clear();
        }
        memset(LCRS,0,sizeof(LCRS));
    }
}

