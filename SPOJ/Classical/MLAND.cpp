#include<bits/stdc++.h>
using namespace std;

double EPS=10e-9;
int no_of_cities,no_of_roads;
pair<pair<int,int>,pair<int,int> >roads[821];
int parent[121];

int find_parent(int index)
{
    if(index==parent[index])return index;
    return parent[index]=find_parent(parent[index]);
}

double minimum_price(double time)
{
    for(int i=0;i<no_of_cities;i++)parent[i]=i;
    priority_queue<pair<double,pair<int,int> >,vector< pair<double,pair<int,int> > >,greater< pair<double,pair<int,int> > > >travelling;
    for(int i=1;i<=no_of_roads;i++)travelling.push(make_pair((double)roads[i].second.second+(double)roads[i].second.first*time,make_pair(roads[i].first.first,roads[i].first.second)));
    double price=0;
    while(!travelling.empty()){
        pair<double,pair<int,int> >cur=travelling.top();
        travelling.pop();
        if(find_parent(cur.second.first)!=find_parent(cur.second.second)){
            parent[find_parent(cur.second.first)]=find_parent(cur.second.second);
            price+=cur.first;
        }
    }
    return price;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        double time1,time2;
        scanf("%d %d",&no_of_cities,&no_of_roads);
        cin>>time1>>time2;
        for(int i=1;i<=no_of_roads;i++)scanf("%d %d %d %d",&roads[i].first.first,&roads[i].first.second,&roads[i].second.first,&roads[i].second.second);

        while(time2-time1>EPS){
            double left=time1+(time2-time1)/3;
            double right=time1+(time2-time1)*2/3;
            if(minimum_price(left)+EPS>minimum_price(right))time2=right;
            else time1=left;
        }

        printf("%.3f %.3f\n",time1,minimum_price(time1));
    }
}
