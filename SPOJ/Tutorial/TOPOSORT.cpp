#include<bits/stdc++.h>
using namespace std;

vector<int>connections[10001];
vector<int>answer;
int visited[10001];

void DepthFirstSearch(int index)
{
    visited[index]=1;
    for(int i=connections[index].size()-1;i>=0;i--){
        if(visited[connections[index][i]]==1){
            printf("Sandro fails.\n");
            exit(0);
        }
        if(visited[connections[index][i]]==0)DepthFirstSearch(connections[index][i]);
    }
    visited[index]=2;
    answer.push_back(index);
    return;
}

int main()
{
    int N,no_of_connections;
    scanf("%d %d",&N,&no_of_connections);
    for(int i=1;i<=no_of_connections;i++){
        int from,to;
        scanf("%d %d",&from,&to);
        connections[from].push_back(to);
    }
    for(int i=1;i<=N;i++){
        visited[i]=0;
        sort(connections[i].begin(),connections[i].end());
    }
    for(int i=N;i>=1;i--)if(visited[i]==0)DepthFirstSearch(i);

    printf("%d",answer[answer.size()-1]);
    for(int i=answer.size()-2;i>=0;i--)printf(" %d",answer[i]);
    printf("\n");
}
