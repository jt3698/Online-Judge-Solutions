#include<bits/stdc++.h>
using namespace std;

bool have[1001][1001];
vector<int>connections[1001],rev_connections[1001];
bool visited[1001],in_cycle[1001];
int cycle[1001],cycle_pointer[1001];
stack<int>ssc;
int cy_da[1001],cy_ke[1001];

int N;

void refresh(int x,int d)
{
    for(int i=0;i<connections[x].size();i++)cy_da[connections[x][i]]+=d;
    for(int i=0;i<rev_connections[x].size();i++)cy_ke[rev_connections[x][i]]+=d;
    return;
}

void dfs(int x)
{
    visited[x]=true;
    for(int i=0;i<connections[x].size();i++){
        int nxt=connections[x][i];
        if(!visited[nxt])dfs(nxt);
    }
    ssc.push(x);
    return;
}

void rev_dfs(int x)
{
    visited[x]=true;
    for(int i=0;i<rev_connections[x].size();i++){
        int nxt=rev_connections[x][i];
        if(!visited[nxt])rev_dfs(nxt);
    }
    return;
}

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        while(getchar()!='\n');
        for(int j=1;j<=N;j++){
            char c=getchar();
            if(c=='1'){
                connections[i].push_back(j);
                rev_connections[j].push_back(i);
                have[i][j]=true;
            }
        }
    }
    int counter=0;
    for(int i=1;i<=N;i++)if(!visited[i]){
        dfs(i);
        counter++;
    }
    memset(visited,false,sizeof(visited));

    counter=0;
    while(!ssc.empty()){
        int v=ssc.top();
        ssc.pop();

        if(!visited[v]){
            counter++;
            rev_dfs(v);
        }
    }
    if(counter!=1){
        printf("impossible\n");
        return 0;
    }

    int par=-1,now;
    for(int i=2;i<=N && par==-1;i++)for(int o=2;o<=N && par==-1;o++)if(i!=o && have[1][i] && have[i][o] && have[o][1]){
        par=i;
        now=o;
    }
    cycle[1]=1;
    cycle_pointer[1]=2;
    cycle[2]=par;
    cycle_pointer[2]=3;
    cycle[3]=now;
    cycle_pointer[3]=1;
    refresh(1,1);
    refresh(par,1);
    refresh(now,1);

    printf("1");
    now=1;
    do{
        now=cycle_pointer[now];
        in_cycle[cycle[now]]=true;
        printf(" %d",cycle[now]);
    }while(now!=1);
    printf("\n");

    for(int p=1;p<=N-3;p++){
        bool found=false;
        for(int i=1;i<=N && !found;i++)if(!in_cycle[i] && cy_da[i]>0 && cy_ke[i]>0){
            for(int o=1;o<=p+2 && !found;o++){
                if(have[cycle[o]][i] && have[i][cycle[cycle_pointer[o]]]){
                    found=true;
                    cycle_pointer[p+3]=cycle_pointer[o];
                    cycle_pointer[o]=p+3;
                    cycle[p+3]=i;
                    in_cycle[i]=true;
                    refresh(i,1);
                }
            }
        }
        if(!found){
            int X,Y;
            for(int i=1;i<=N && !found;i++)if(!in_cycle[i] && have[1][i]){
                for(int j=0;j<connections[i].size() && !found;j++){
                    int x=connections[i][j];
                    if(!in_cycle[x] && have[x][1]){
                        X=i;
                        Y=x;
                        found=true;
                    }
                }
            }
            in_cycle[cycle[cycle_pointer[1]]]=false;
            in_cycle[X]=true;
            in_cycle[Y]=true;
            refresh(cycle[cycle_pointer[1]],-1);
            cycle[cycle_pointer[1]]=X;
            cycle_pointer[p+3]=cycle_pointer[cycle_pointer[1]];
            cycle_pointer[cycle_pointer[1]]=p+3;
            cycle[p+3]=Y;
            refresh(X,1);
            refresh(Y,1);
        }

        printf("1");
        now=1;
        do{
            now=cycle_pointer[now];
            printf(" %d",cycle[now]);
        }while(cycle[now]!=1);
        printf("\n");
    }
}
