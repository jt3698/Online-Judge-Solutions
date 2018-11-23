#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL MOD=1000000007;
string G,P;
string Gans,Pans;
int vis[1000001][2][2],vis3[1000001][2][2]; ///Flip 1-Must flip soon, 0-Must never flip
LL store[1000001][2][2],store3[1000001][2][2];
int N,test;

LL ways(int x,int flip,int num_before)
{
    if(x==N){
        if(flip==1)return (LL)0;
        return (LL)1;
    }

    if(vis[x][flip][num_before]==test)return store[x][flip][num_before];
    vis[x][flip][num_before]=test;

    LL res=0;
    int this_num;
    if(x==0){
        if(G[x]=='1'){
            this_num=1;
            if(P[x]=='1')res+=ways(x+1,0,this_num);
            else if(P[x]=='0')res+=ways(x+1,1,this_num);
            else res+=(ways(x+1,0,this_num)+ways(x+1,1,this_num));
        }
        else if(G[x]=='0'){
            this_num=0;
            if(P[x]=='1')res+=ways(x+1,1,this_num);
            else if(P[x]=='0')res+=ways(x+1,0,this_num);
            else res+=(ways(x+1,1,this_num)+ways(x+1,0,this_num));
        }
        else{
            this_num=1;
            if(P[x]=='1')res+=ways(x+1,0,this_num);
            else if(P[x]=='0')res+=ways(x+1,1,this_num);
            else res+=(ways(x+1,0,this_num)+ways(x+1,1,this_num));
            this_num=0;
            if(P[x]=='1')res+=ways(x+1,1,this_num);
            else if(P[x]=='0')res+=ways(x+1,0,this_num);
            else res+=(ways(x+1,1,this_num)+ways(x+1,0,this_num));
        }
        res%=MOD;
        return store[x][flip][num_before]=res;
    }

    if(flip==1){
        /*Do flip now*/
        if(G[x]=='1'){
            if(num_before==1)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=ways(x+1,0,this_num);
                else if(P[x]=='0')res+=0;
                else res+=ways(x+1,0,this_num);
            }
            else res+=0;
        }
        else if(G[x]=='0'){
            if(num_before==0)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=ways(x+1,0,this_num);
                else if(P[x]=='0')res+=0;
                else res+=ways(x+1,0,this_num);
            }
            else res+=0;
        }
        else{
            if(num_before==1)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=ways(x+1,0,this_num);
                else if(P[x]=='0')res+=0;
                else res+=ways(x+1,0,this_num);
            }
            else res+=0;

            if(num_before==0)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=ways(x+1,0,this_num);
                else if(P[x]=='0')res+=0;
                else res+=ways(x+1,0,this_num);
            }
            else res+=0;
        }

        /*Give to next guy*/
        if(G[x]=='1'){
            if(num_before==1)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways(x+1,flip,this_num);
                else res+=ways(x+1,flip,this_num);
            }
            else{
                if(P[x]=='0')res+=0;
                else if(P[x]=='1')res+=ways(x+1,flip,this_num);
                else res+=ways(x+1,flip,this_num);
            }
        }
        else if(G[x]=='0'){
            if(num_before==0)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways(x+1,flip,this_num);
                else res+=ways(x+1,flip,this_num);
            }
            else{
                if(P[x]=='0')res+=0;
                else if(P[x]=='1')res+=ways(x+1,flip,this_num);
                else res+=ways(x+1,flip,this_num);
            }
        }
        else{
            if(num_before==1)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways(x+1,flip,this_num);
                else res+=ways(x+1,flip,this_num);
            }
            else{
                if(P[x]=='0')res+=0;
                else if(P[x]=='1')res+=ways(x+1,flip,this_num);
                else res+=ways(x+1,flip,this_num);
            }

            if(num_before==0)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways(x+1,flip,this_num);
                else res+=ways(x+1,flip,this_num);
            }
            else{
                if(P[x]=='0')res+=0;
                else if(P[x]=='1')res+=ways(x+1,flip,this_num);
                else res+=ways(x+1,flip,this_num);
            }
        }
    }
    else{
        if(G[x]=='1'){
            if(num_before==1)this_num=0;
            else this_num=1;

            if(this_num==1)res+=0;
            else{
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways(x+1,flip,this_num);
                else res+=ways(x+1,flip,this_num);
            }
        }
        else if(G[x]=='0'){
            if(num_before==1)this_num=1;
            else this_num=0;

            if(this_num==1)res+=0;
            else{
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways(x+1,flip,this_num);
                else res+=ways(x+1,flip,this_num);
            }
        }
        else{
            if(num_before==1)this_num=0;
            else this_num=1;

            if(this_num==1)res+=0;
            else{
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways(x+1,flip,this_num);
                else res+=ways(x+1,flip,this_num);
            }

            if(num_before==1)this_num=1;
            else this_num=0;

            if(this_num==1)res+=0;
            else{
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways(x+1,flip,this_num);
                else res+=ways(x+1,flip,this_num);
            }
        }
    }

    res%=MOD;
    return store[x][flip][num_before]=res;
}

LL ways3(int x,int flip,int num_before)
{
    if(x==N){
        if(flip==1)return 0;
        return 1;
    }

    if(vis3[x][flip][num_before]==test)return store3[x][flip][num_before];
    vis3[x][flip][num_before]=test;

    LL res=0;
    int this_num;
    if(x==0){
        if(G[x]=='1'){
            this_num=1;
            if(P[x]=='1')res+=ways3(x+1,0,this_num);
            else if(P[x]=='0')res+=ways3(x+1,1,this_num);
            else{
                res+=ways3(x+1,0,this_num);
                if(res==1){
                    Pans+='1';
                    return store3[x][flip][num_before]=1;
                }
                res+=ways3(x+1,1,this_num);
                if(res==1){
                    Pans+='0';
                    return store3[x][flip][num_before]=1;
                }
            }
        }
        else if(G[x]=='0'){
            this_num=0;
            if(P[x]=='1')res+=ways3(x+1,1,this_num);
            else if(P[x]=='0')res+=ways3(x+1,0,this_num);
            else{
                res+=ways3(x+1,1,this_num);
                if(res==1){
                    Pans+='1';
                    return store3[x][flip][num_before]=1;
                }
                res+=ways3(x+1,0,this_num);
                if(res==1){
                    Pans+='0';
                    return store3[x][flip][num_before]=1;
                }
            }
        }
        else{
            this_num=1;
            if(P[x]=='1')res+=ways3(x+1,0,this_num);
            else if(P[x]=='0')res+=ways3(x+1,1,this_num);
            else{
                res+=ways3(x+1,0,this_num);
                if(res==1){
                    Pans+='1';
                    Gans+='1';
                    return store3[x][flip][num_before]=1;
                }
                res+=ways3(x+1,1,this_num);
                if(res==1){
                    Pans+='0';
                    Gans+='1';
                    return store3[x][flip][num_before]=1;
                }
            }
            if(res==1){
                Gans+='1';
                return store3[x][flip][num_before]=1;
            }

            this_num=0;
            if(P[x]=='1')res+=ways3(x+1,1,this_num);
            else if(P[x]=='0')res+=ways3(x+1,0,this_num);
            else{
                res+=ways3(x+1,1,this_num);
                if(res==1){
                    Pans+='1';
                    Gans+='0';
                    return store3[x][flip][num_before]=1;
                }
                res+=ways3(x+1,0,this_num);
                if(res==1){
                    Pans+='0';
                    Gans+='0';
                    return store3[x][flip][num_before]=1;
                }
            }
            if(res==1){
                Gans+='0';
                return store3[x][flip][num_before]=1;
            }
        }
        res=min(res,(LL)2);
        return store3[x][flip][num_before]=res;
    }

    if(flip==1){
        /*Do flip now*/
        if(G[x]=='1'){
            if(num_before==1)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=ways3(x+1,0,this_num);
                else if(P[x]=='0')res+=0;
                else{
                    res+=ways3(x+1,0,this_num);
                    if(res==1){
                        Pans+='1';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
            else res+=0;
        }
        else if(G[x]=='0'){
            if(num_before==0)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=ways3(x+1,0,this_num);
                else if(P[x]=='0')res+=0;
                else{
                    res+=ways3(x+1,0,this_num);
                    if(res==1){
                        Pans+='1';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
            else res+=0;
        }
        else{
            if(num_before==1)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=ways3(x+1,0,this_num);
                else if(P[x]=='0')res+=0;
                else{
                    res+=ways3(x+1,0,this_num);
                    if(res==1){
                        Pans+='1';
                        Gans+='1';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
            else res+=0;
            if(res==1){
                Gans+='1';
                return store3[x][flip][num_before]=1;
            }

            if(num_before==0)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=ways3(x+1,0,this_num);
                else if(P[x]=='0')res+=0;
                else{
                    res+=ways3(x+1,0,this_num);
                    if(res==1){
                        Pans+='1';
                        Gans+='0';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
            else res+=0;
            if(res==1){
                Gans+='0';
                return store3[x][flip][num_before]=1;
            }
        }

        /*Give to next guy*/
        if(G[x]=='1'){
            if(num_before==1)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways3(x+1,flip,this_num);
                else{
                    res+=ways3(x+1,flip,this_num);
                    if(res==1){
                        Pans+='0';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
            else{
                if(P[x]=='0')res+=0;
                else if(P[x]=='1')res+=ways3(x+1,flip,this_num);
                else{
                    res+=ways3(x+1,flip,this_num);
                    if(res==1){
                        Pans+='1';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
        }
        else if(G[x]=='0'){
            if(num_before==0)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways3(x+1,flip,this_num);
                else{
                    res+=ways3(x+1,flip,this_num);
                    if(res==1){
                        Pans+='0';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
            else{
                if(P[x]=='0')res+=0;
                else if(P[x]=='1')res+=ways3(x+1,flip,this_num);
                else{
                    res+=ways3(x+1,flip,this_num);
                    if(res==1){
                        Pans+='1';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
        }
        else{
            if(num_before==1)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways3(x+1,flip,this_num);
                else{
                    res+=ways3(x+1,flip,this_num);
                    if(res==1){
                        Pans+='0';
                        Gans+='1';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
            else{
                if(P[x]=='0')res+=0;
                else if(P[x]=='1')res+=ways3(x+1,flip,this_num);
                else{
                    res+=ways3(x+1,flip,this_num);
                    if(res==1){
                        Pans+='1';
                        Gans+='1';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
            if(res==1){
                Gans+='1';
                return store3[x][flip][num_before]=1;
            }

            if(num_before==0)this_num=0;
            else this_num=1;

            if(this_num==1){
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways3(x+1,flip,this_num);
                else{
                    res+=ways3(x+1,flip,this_num);
                    if(res==1){
                        Gans+='0';
                        Pans+='0';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
            else{
                if(P[x]=='0')res+=0;
                else if(P[x]=='1')res+=ways3(x+1,flip,this_num);
                else{
                    res+=ways3(x+1,flip,this_num);
                    if(res==1){
                        Gans+='0';
                        Pans+='1';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
            if(res==1){
                Gans+='0';
                return store3[x][flip][num_before]=1;
            }
        }
    }
    else{
        if(G[x]=='1'){
            if(num_before==1)this_num=0;
            else this_num=1;

            if(this_num==1)res+=0;
            else{
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways3(x+1,flip,this_num);
                else{
                    res+=ways3(x+1,flip,this_num);
                    if(res==1){
                        Pans+='0';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
        }
        else if(G[x]=='0'){
            if(num_before==1)this_num=1;
            else this_num=0;

            if(this_num==1)res+=0;
            else{
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways3(x+1,flip,this_num);
                else{
                    res+=ways3(x+1,flip,this_num);
                    if(res==1){
                        Pans+='0';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
        }
        else{
            if(num_before==1)this_num=0;
            else this_num=1;

            if(this_num==1)res+=0;
            else{
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways3(x+1,flip,this_num);
                else{
                    res+=ways3(x+1,flip,this_num);
                    if(res==1){
                        Pans+='0';
                        Gans+='1';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
            if(res==1){
                Gans+='1';
                return store3[x][flip][num_before]=1;
            }

            if(num_before==1)this_num=1;
            else this_num=0;

            if(this_num==1)res+=0;
            else{
                if(P[x]=='1')res+=0;
                else if(P[x]=='0')res+=ways3(x+1,flip,this_num);
                else{
                    res+=ways3(x+1,flip,this_num);
                    if(res==1){
                        Gans+='0';
                        Pans+='0';
                        return store3[x][flip][num_before]=1;
                    }
                }
            }
            if(res==1){
                Gans+='0';
                return store3[x][flip][num_before]=1;
            }
        }
    }

    return store3[x][flip][num_before]=min(res,(LL)2);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(test=1;test<=T;test++){
        cin>>G>>P;

        Gans="";Pans="";
        N=G.size();
        LL temp=ways(0,0,0);
        if(temp==(LL)1){
            printf("UNIQUE\n");
            ways3(0,0,0);
            int Gc=(int)Gans.size()-1;
            int Pc=(int)Pans.size()-1;
            for(int i=0;i<G.size();i++){
                if(G[i]=='?')printf("%c",Gans[Gc--]);
                else printf("%c",G[i]);
            }
            printf("\n");
            for(int i=0;i<P.size();i++){
                if(P[i]=='?')printf("%c",Pans[Pc--]);
                else printf("%c",P[i]);
            }
            printf("\n");
        }
        else if(temp==(LL)0){
            printf("IMPOSSIBLE\n");
        }
        else{
            printf("AMBIGUOUS %lld\n",temp);
        }
    }
}
