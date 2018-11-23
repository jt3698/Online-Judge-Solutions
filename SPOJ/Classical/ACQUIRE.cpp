#include<bits/stdc++.h>
#define LL long long
using namespace std;

pair<LL,LL>rectangles[50001],ori[50001];
LL store[50001];
int counter=0;

struct Line
{
    LL m,c;
    int whose;
}lines[50001];

int no_of_lines;

void add_line(LL mx,LL cx,int x)
{
    while(no_of_lines>=2){
        Line L1=lines[no_of_lines-1];
        Line L2=lines[no_of_lines];
        Line L3;
        L3.m=mx;
        L3.c=cx;
        if((L3.c-L2.c)*(L1.m-L3.m)>(L3.c-L1.c)*(L2.m-L3.m))break;
        no_of_lines--;
    }
    no_of_lines++;
    lines[no_of_lines].m=mx;
    lines[no_of_lines].c=cx;
    lines[no_of_lines].whose=x;
    return;
}

int find_best(LL x)
{
    int l=1,r=no_of_lines;
    while(l<r){
        int mid=(l+r)/2;

        Line L1=lines[mid];
        Line L2=lines[mid+1];

        if(L2.m*x+L2.c<L1.m*x+L1.c)l=mid+1;
        else r=mid;
    }

    return lines[l].whose;
}

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)scanf("%lld %lld",&ori[i].first,&ori[i].second);
    sort(ori+1,ori+N+1);

    for(int i=1;i<=N;i++){
        while(counter>0 && ori[i].second>=rectangles[counter].second)counter--;
        rectangles[++counter]=ori[i];
    }

    for(int i=1;i<=counter;i++){
        store[i]=rectangles[i].first*rectangles[i].second+store[i-1];
       // for(int o=i-1;o>=1;o--)store[i]=min(store[i],rectangles[i].first*rectangles[o].second+store[o-1]);
        if(i>1){
            int best=find_best(rectangles[i].first);
            store[i]=min(store[i],rectangles[i].first*rectangles[best].second+store[best-1]);
        }
        add_line(rectangles[i].second,store[i-1],i);
    }

    printf("%lld\n",store[counter]);
}
