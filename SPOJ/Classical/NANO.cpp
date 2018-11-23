#include<bits/stdc++.h>
#define LL long long int
#define MOD 1000000007
#define eps 10e-9
using namespace std;

vector<pair<int,double> >connections[250001];
priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > >travelling;
int visited[250001];
int temp;char c;

int main()
{
    int T=0;
    c=getchar();
    while(c!=' ' && c!='\n'){
        T*=10;
        T+=(c-'0');
        c=getchar();
    }
    for(int test=1;test<=T;test++){
        double start_t;
        int N,M;

        temp=0;
        c=getchar();
        while(c!=' ' && c!='\n'){
            temp*=10;
            temp+=(c-'0');
            c=getchar();
        }

        N=0;
        c=getchar();
        while(c!=' ' && c!='\n'){
            N*=10;
            N+=(c-'0');
            c=getchar();
        }

        M=0;
        c=getchar();
        while(c!=' ' && c!='\n'){
            M*=10;
            M+=(c-'0');
            c=getchar();
        }

        start_t=(double)temp;
        for(int i=1;i<=M;i++){
            int A,B;
            double dist;
            A=0;
            c=getchar();
            while(c!=' ' && c!='\n'){
                A*=10;
                A+=(c-'0');
                c=getchar();
            }

            B=0;
            c=getchar();
            while(c!=' ' && c!='\n'){
                B*=10;
                B+=(c-'0');
                c=getchar();
            }

            temp=0;
            c=getchar();
            while(c!=' ' && c!='\n'){
                temp*=10;
                temp+=(c-'0');
                c=getchar();
            }

            dist=(double)temp;
            A++;B++;
            connections[A].push_back(make_pair(B,dist));
        }

        double ans=-1;
        if(start_t<=eps)start_t=eps;
        travelling.push(make_pair(start_t,1));
        visited[1]=test;
        bool hv=false;
        while(!travelling.empty()){
            pair<double,int>cur=travelling.top();
            travelling.pop();

            double time=cur.first;
            int city=cur.second;

            if(city==N){
                ans=time;
                hv=true;
                break;
            }

            if(visited[city]!=test*2){
                visited[city]=test*2;
                for(int i=0;i<connections[city].size();i++){
                    int nxt=connections[city][i].first;
                    if(visited[nxt]!=test*2 && visited[nxt]!=test*2-1){
                        double dist=connections[city][i].second;
                        if(dist<=eps){
                            travelling.push(make_pair(time,nxt));
                            visited[nxt]=test*2-1;
                        }
                        else if(time<=sqrt(dist)+eps){
                            travelling.push(make_pair(sqrt(dist)*2,nxt));
                            visited[nxt]=test*2-1;
                        }
                        else travelling.push(make_pair(time+dist/time,nxt));
                    }
                }
            }
        }

        if(!hv)printf("Impossible\n");
        else printf("%.11lf\n",ans);

        if(test<T){
            for(int i=1;i<=N;i++)connections[i].clear();
            travelling=priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > >();
        }
    }
    return 0;
}
