#include<bits/stdc++.h>
#define LL long long int
using namespace std;

int inspectors[1011];
LL cost[1000011];
bool ticket_office[1000011];
pair<int,int>buying_points[1011];
vector<pair<int,int> >printing;
int N,K;
LL D;

int answer[1011][1011],best_answer[1010];
LL store[1011][1011],best_store[1010];

void answer_printing(int no_inspect,int safe_inspect)
{
    if(safe_inspect==K)return;
    if(answer[no_inspect][safe_inspect]==0){
        answer_printing(no_inspect+1,safe_inspect);
        return;
    }

    if(answer[no_inspect][safe_inspect]%2==0){
        int travelled=inspectors[answer[no_inspect][safe_inspect]/2]+1-buying_points[no_inspect].second;
        printing.push_back(make_pair(buying_points[no_inspect].second,travelled));
        answer_printing(no_inspect+1,answer[no_inspect][safe_inspect]/2);
        return;
    }
    else{
        int travelled=inspectors[(answer[no_inspect][safe_inspect]+1)/2]+1-buying_points[no_inspect].first;
        printing.push_back(make_pair(buying_points[no_inspect].first,travelled));
        answer_printing(no_inspect+1,(answer[no_inspect][safe_inspect]+1)/2);
        return;
    }
}

LL fast()
{
    LL res=0;
    char c;
    c=getchar();
    while(c!=' ' && c!='\n'){
        res*=10;
        res+=c-'0';
        c=getchar();
    }
    return res;
}

int fasti()
{
    int res=0;
    char c;
    c=getchar();
    while(c!=' ' && c!='\n'){
        res*=10;
        res+=c-'0';
        c=getchar();
    }
    return res;
}

int main()
{
    int T;
    T=fasti();
    for(int test=1;test<=T;test++){
        memset(best_answer,0,sizeof(best_answer));
        memset(best_store,0,sizeof(best_store));
        printing.clear();

        N=fasti();
        K=fast();
        D=fast();
        for(int i=1;i<=N;i++){
            char c=getchar();
            if(c=='1')ticket_office[i]=true;
            else ticket_office[i]=false;
        }
        ticket_office[1]=false;
        while(getchar()!='\n');
        for(int i=1;i<N;i++)cost[i]=fast();
        for(int i=1;i<=K;i++)inspectors[i]=fasti();

        for(int i=1;i<=K;i++){
            int s=inspectors[i-1]+1,e=inspectors[i];
            buying_points[i]=make_pair(-1,-1);
            for(int o=s;o<=e;o++){
                if(ticket_office[o])buying_points[i].second=o;
                else buying_points[i].first=o;
            }
        }

        for(int i=0;i<=K;i++)store[K+1][i]=0;
        for(int no_inspect=K;no_inspect>=1;no_inspect--){
            ///safe_inspect+1==no_inspect
            LL res,ans;

            res=10e17;ans=0;
            if(buying_points[no_inspect].first!=-1){
                LL temp=cost[inspectors[no_inspect]+1-buying_points[no_inspect].first]+store[no_inspect+1][no_inspect];
                if(temp<res){
                    res=temp;
                    ans=no_inspect*2-1;
                }
            }
            if(buying_points[no_inspect].second!=-1){
                LL temp=D+cost[inspectors[no_inspect]+1-buying_points[no_inspect].second]+store[no_inspect+1][no_inspect];
                if(temp<res){
                    res=temp;
                    ans=no_inspect*2;
                }
            }

            for(int i=no_inspect+1;i<=K;i++){
                if(buying_points[no_inspect].first!=-1){
                    LL temp=cost[inspectors[i]+1-buying_points[no_inspect].first]+store[no_inspect+1][i];
                    if(temp<res){
                        res=temp;
                        ans=i*2-1;
                    }
                }
                if(buying_points[no_inspect].second!=-1){
                    LL temp=D+cost[inspectors[i]+1-buying_points[no_inspect].second]+store[no_inspect+1][i];
                    if(temp<res){
                        res=temp;
                        ans=i*2;
                    }
                }
            }

            answer[no_inspect][no_inspect-1]=ans;
            store[no_inspect][no_inspect-1]=res;

            ///safe_inspect>=no_inspect
            store[no_inspect][K]=0;
            answer[no_inspect][K]=0;
            best_store[no_inspect]=10e16;
            if(buying_points[no_inspect-1].first!=-1){
                LL temp=0+cost[inspectors[K]+1-buying_points[no_inspect-1].first];
                if(temp<best_store[no_inspect]){
                    best_store[no_inspect]=temp;
                    best_answer[no_inspect]=K*2-1;
                }
            }
            if(buying_points[no_inspect-1].second!=-1){
                LL temp=0+D+cost[inspectors[K]+1-buying_points[no_inspect-1].second];
                if(temp<best_store[no_inspect]){
                    best_store[no_inspect]=temp;
                    best_answer[no_inspect]=K*2;
                }
            }

            for(int safe_inspect=no_inspect;safe_inspect<K;safe_inspect++){
                res=store[no_inspect+1][safe_inspect];
                ans=0;

                LL temp=best_store[no_inspect+1];
                if(temp<res){
                    res=temp;
                    ans=best_answer[no_inspect+1];
                }

                answer[no_inspect][safe_inspect]=ans;
                store[no_inspect][safe_inspect]=res;

                if(buying_points[no_inspect-1].first!=-1){
                    LL temp=res+cost[inspectors[safe_inspect]+1-buying_points[no_inspect-1].first];
                    if(temp<best_store[no_inspect]){
                        best_store[no_inspect]=temp;
                        best_answer[no_inspect]=safe_inspect*2-1;
                    }
                }
                if(buying_points[no_inspect-1].second!=-1){
                    LL temp=res+D+cost[inspectors[safe_inspect]+1-buying_points[no_inspect-1].second];
                    if(temp<best_store[no_inspect]){
                        best_store[no_inspect]=temp;
                        best_answer[no_inspect]=safe_inspect*2;
                    }
                }
            }
        }

        printf("%d",store[1][0]);
        answer_printing(1,0);
        printf(" %d\n",printing.size());
        for(int i=0;i<printing.size();i++)printf("%d %d\n",printing[i].first,printing[i].second);
    }
}
