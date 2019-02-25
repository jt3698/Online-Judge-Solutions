#include<bits/stdc++.h>
using namespace std;

int rows,columns;
bool grid[51][51];
int visited[51][51][5];
int end_x,end_y;
bool found;

bool safe(pair<pair<int,int>,int>cur,int steps)
{
    if(cur.second==1)cur.first.first-=steps;
    else if(cur.second==2)cur.first.second+=steps;
    else if(cur.second==3)cur.first.first+=steps;
    else cur.first.second-=steps;

    if(cur.first.first>=rows || cur.first.first==0)return false;
    if(cur.first.second>=columns || cur.first.second==0)return false;
    if(cur.first.first<rows && cur.first.first>=0 && cur.first.second<columns && cur.first.second>=0){
        if(grid[cur.first.first][cur.first.second])return false;
    }
    if(cur.first.first-1<rows && cur.first.first-1>=0 && cur.first.second<columns && cur.first.second>=0){
        if(grid[cur.first.first-1][cur.first.second])return false;
    }
    if(cur.first.first<rows && cur.first.first>=0 && cur.first.second-1<columns && cur.first.second-1>=0){
        if(grid[cur.first.first][cur.first.second-1])return false;
    }
    if(cur.first.first-1<rows && cur.first.first-1>=0 && cur.first.second-1<columns && cur.first.second-1>=0){
        if(grid[cur.first.first-1][cur.first.second-1])return false;
    }

    return true;
}

void BreadthFirstSearch(int begin_y,int begin_x,int direction)
{
    visited[begin_y][begin_x][direction]=0;
    if(begin_y==end_y && begin_x==end_x)found=true;
    queue<pair<pair<int,int>,int> >BFS;
    BFS.push(make_pair(make_pair(begin_y,begin_x),direction));
    while(!BFS.empty() && !found){
        pair<pair<int,int>,int>cur=BFS.front();
        BFS.pop();

        pair<pair<int,int>,int>next;

        ///TURN
        next.first.first=cur.first.first;
        next.first.second=cur.first.second;
            ///LEFT
        next.second=(cur.second+2)%4+1;

        if(visited[next.first.first][next.first.second][next.second]==-1){
            visited[next.first.first][next.first.second][next.second]=visited[cur.first.first][cur.first.second][cur.second]+1;
            BFS.push(next);
        }
            ///RIGHT
        next.second=cur.second%4+1;

        if(visited[next.first.first][next.first.second][next.second]==-1){
            visited[next.first.first][next.first.second][next.second]=visited[cur.first.first][cur.first.second][cur.second]+1;
            BFS.push(next);
        }

        ///GO
        next.second=cur.second;
        int steps=1;
        while(safe(cur,steps) && steps<=3 && !found){
            if(cur.second==1){
                next.first.first=cur.first.first-steps;
                next.first.second=cur.first.second;
            }
            else if(cur.second==2){
                next.first.first=cur.first.first;
                next.first.second=cur.first.second+steps;
            }
            else if(cur.second==3){
                next.first.first=cur.first.first+steps;
                next.first.second=cur.first.second;
            }
            else{
                next.first.first=cur.first.first;
                next.first.second=cur.first.second-steps;
            }

            if(visited[next.first.first][next.first.second][next.second]==-1){
                visited[next.first.first][next.first.second][next.second]=visited[cur.first.first][cur.first.second][cur.second]+1;
                BFS.push(next);
                if(next.first.first==end_y && next.first.second==end_x)found=true;
            }

            steps++;
        }
    }
}

int main()
{
  //  freopen("output.txt","w",stdout);
    scanf("%d %d\n",&rows,&columns);
    while(rows!=0 || columns!=0){

        memset(visited,-1,sizeof(visited));

        for(int y=0;y<rows;y++)for(int x=0;x<columns;x++)scanf("%d",&grid[y][x]);
        //for(int y=0;y<rows;y++,cout<<endl)for(int x=0;x<columns;x++)printf("%d ",grid[y][x]);

        int begin_y,begin_x;
        scanf("%d %d %d %d ",&begin_y,&begin_x,&end_y,&end_x);

        string direction;
        cin>>direction;

        found=false;

        if(direction=="north")BreadthFirstSearch(begin_y,begin_x,1);
        else if(direction=="east")BreadthFirstSearch(begin_y,begin_x,2);
        else if(direction=="south")BreadthFirstSearch(begin_y,begin_x,3);
        else BreadthFirstSearch(begin_y,begin_x,4);

        if(found){
            for(int i=1;i<=4;i++)if(visited[end_y][end_x][i]!=-1)printf("%d\n",visited[end_y][end_x][i]);
        }
        else printf("-1\n");
        scanf("%d %d",&rows,&columns);
    }
}
