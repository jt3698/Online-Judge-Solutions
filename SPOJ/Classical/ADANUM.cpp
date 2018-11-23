#include<bits/stdc++.h>
#define LL long long int
using namespace std;

int vegetables[200001],how_many[200001];
map<LL,int>compression;
int idx=1;
LL answers[200001],price;
vector<int>price_measure;
int address[200001];
int counter_start[200001],counter_ends[200001];

struct Query
{
    int l,r;
    int number;
}queries[200001];

bool cmp(Query A,Query B)
{
    int square=700;
    if(A.l/square<B.l/square)return true;
    if(A.l/square==B.l/square)return A.r<B.r;
    return false;
}

void put_in(int x)
{
    if(address[vegetables[x]]==-1){
        price_measure.push_back(vegetables[x]);
        address[vegetables[x]]=price_measure.size()-1;

        how_many[vegetables[x]]++;
        if(counter_start[how_many[vegetables[x]]]==-1)counter_start[how_many[vegetables[x]]]=address[vegetables[x]];
        counter_ends[how_many[vegetables[x]]]=address[vegetables[x]];
        price+=(LL)address[vegetables[x]]+1;
        return;
    }

    int temp=address[vegetables[x]];
    swap(address[vegetables[x]],address[price_measure[counter_start[how_many[vegetables[x]]]]]);
    swap(price_measure[temp],price_measure[counter_start[how_many[vegetables[x]]]]);

    if(address[vegetables[x]]+1<price_measure.size()
        && how_many[price_measure[address[vegetables[x]]+1]]==how_many[vegetables[x]])
            counter_start[how_many[vegetables[x]]]=address[vegetables[x]]+1;
    else{
        counter_start[how_many[vegetables[x]]]=-1;
        counter_ends[how_many[vegetables[x]]]=-1;
    }

    how_many[vegetables[x]]++;
    if(counter_start[how_many[vegetables[x]]]==-1)counter_start[how_many[vegetables[x]]]=address[vegetables[x]];
    counter_ends[how_many[vegetables[x]]]=address[vegetables[x]];
    price+=(LL)address[vegetables[x]]+1;
    return;
}

void put_out(int x)
{
    int temp=address[vegetables[x]];
    swap(address[vegetables[x]],address[price_measure[counter_ends[how_many[vegetables[x]]]]]);
    swap(price_measure[temp],price_measure[counter_ends[how_many[vegetables[x]]]]);

    if(address[vegetables[x]]-1>=0
        && how_many[price_measure[address[vegetables[x]]-1]]==how_many[vegetables[x]])
            counter_ends[how_many[vegetables[x]]]=address[vegetables[x]]-1;
    else{
        counter_start[how_many[vegetables[x]]]=-1;
        counter_ends[how_many[vegetables[x]]]=-1;
    }

    how_many[vegetables[x]]--;
    if(counter_ends[how_many[vegetables[x]]]==-1)counter_ends[how_many[vegetables[x]]]=address[vegetables[x]];
    counter_start[how_many[vegetables[x]]]=address[vegetables[x]];
    price=price-(LL)address[vegetables[x]]-1;

    if(how_many[vegetables[x]]==0){
        price_measure.pop_back();
        address[vegetables[x]]=-1;
    }
    return;
}

int fast()
{
    char c;
    int res=0;
    c=getchar();
    while(c!=' ' && c!='\n'){
        res*=10;
        res+=(c-'0');
        c=getchar();
    }
    return res;
}


LL fastll()
{
    char c;
    LL res=0;
    c=getchar();
    while(c!=' ' && c!='\n'){
        res*=10;
        res+=(c-'0');
        c=getchar();
    }
    return res;
}

int main()
{
    int N,Q;
    scanf("%d %d\n",&N,&Q);
    for(int i=1;i<=N;i++){
        LL temp;
        temp=fastll();
        if(compression[temp])vegetables[i]=compression[temp];
        else{
            compression[temp]=idx;
            vegetables[i]=idx;
            idx++;
        }
    }
    for(int i=1;i<=Q;i++){
        queries[i].l=fast();
        queries[i].r=fast();
        queries[i].number=i;
    }
    sort(queries+1,queries+Q+1,cmp);

    int last_right=N+1;
    int l_now,r_now;
    for(int q=1;q<=Q;q++){
        if(queries[q].r<last_right){
            l_now=queries[q].l;
            r_now=l_now-1;
            price=0;
            price_measure.clear();
            memset(how_many,0,sizeof(how_many));
            memset(counter_start,-1,sizeof(counter_start));
            memset(counter_ends,-1,sizeof(counter_ends));
            memset(address,-1,sizeof(address));
        }

        while(r_now<queries[q].r)put_in(++r_now);
        while(l_now<queries[q].l)put_out(l_now++);
        while(l_now>queries[q].l)put_in(--l_now);

        answers[queries[q].number]=price;
        last_right=queries[q].r;
    }

    for(int q=1;q<=Q;q++)printf("%lld\n",answers[q]);
}
