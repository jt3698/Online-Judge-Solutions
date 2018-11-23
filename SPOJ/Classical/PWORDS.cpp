#include<bits/stdc++.h>
//#define char() char_unlocked()
#define LL long long int
using namespace std;

char ad1[13],ad2[13];
int len1,len2;
LL store1[251][1024][2],store2[251][1024][2];
int first1[27],first2[27],last1[27],last2[27];

LL ways1(int dist_left,int bitmask,int change)
{
    if(bitmask==(1<<len1)-1){
        if(dist_left==0 && change==0)return 1;
        return 0;
    }

    if(store1[dist_left][bitmask][change]!=-1)return store1[dist_left][bitmask][change];

    int which_letter=0;
    for(int i=0;i<len1;i++)if(bitmask & (1<<i))which_letter++;

    LL ans=0;

    for(int i=0;i<len1;i++)if(!(bitmask & (1<<i))){
        bool can;

        can=true;
        if(i>0)
            if(ad1[i-1]==ad1[i] && !(bitmask & (1<<(i-1))))can=false;
        int x=ad1[which_letter];
        int y=ad1[i];
        if(can){
            if(dist_left>=abs(y-x))ans+=ways1(dist_left-abs(y-x),bitmask | (1<<i),change);

            if(change==1){
                if(last1[ad1[i]-'a'-1]==-1 || (bitmask & (1<<last1[ad1[i]-'a'-1])))
                    if(dist_left>=abs(y-1-x))ans+=ways1(dist_left-abs(y-1-x),bitmask | (1<<i),change-1);
                if(first1[ad1[i]-'a'+1]==-1 || !(bitmask & (1<<first1[ad1[i]-'a'+1])))
                    if(dist_left>=abs(y+1-x))ans+=ways1(dist_left-abs(y+1-x),bitmask | (1<<i),change-1);
            }
        }
    }

    return store1[dist_left][bitmask][change]=ans;
}

LL ways2(int dist_left,int bitmask,int change)
{
    if(bitmask==(1<<len2)-1){
        if(dist_left==0 && change==0)return 1;
        return 0;
    }

    if(store2[dist_left][bitmask][change]!=-1)return store2[dist_left][bitmask][change];

    int which_letter=0;
    for(int i=0;i<len2;i++)if(bitmask & (1<<i))which_letter++;

    LL ans=0;

    for(int i=0;i<len2;i++)if(!(bitmask & (1<<i))){
        bool can;

        can=true;
        if(i>0)
            if(ad2[i-1]==ad2[i] && !(bitmask & (1<<(i-1))))can=false;
        int x=ad2[which_letter];
        int y=ad2[i];
        if(can){
            if(dist_left>=abs(y-x))ans+=ways2(dist_left-abs(y-x),bitmask | (1<<i),change);

            if(change==1){
                if(last2[ad2[i]-'a'-1]==-1 || (bitmask & (1<<last2[ad2[i]-'a'-1])))
                    if(dist_left>=abs(y-1-x))ans+=ways2(dist_left-abs(y-1-x),bitmask | (1<<i),change-1);
                if(first2[ad2[i]-'a'+1]==-1 || !(bitmask & (1<<first2[ad2[i]-'a'+1])))
                    if(dist_left>=abs(y+1-x))ans+=ways2(dist_left-abs(y+1-x),bitmask | (1<<i),change-1);
            }
        }
    }

    return store2[dist_left][bitmask][change]=ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        len1=0;
        while(getchar()!='\n');
        ad1[len1]=getchar();
        while(ad1[len1]!=' ')ad1[++len1]=getchar();

        len2=0;
        ad2[len2]=getchar();
        while(ad2[len2]!=' ')ad2[++len2]=getchar();

        memset(first1,-1,sizeof(first1));
        memset(last1,-1,sizeof(last1));
        sort(ad1,ad1+len1);
        for(int i=0;i<len1;i++){
            if(first1[ad1[i]-'a']==-1)first1[ad1[i]-'a']=i;
            last1[ad1[i]-'a']=i;
        }
        memset(first2,-1,sizeof(first2));
        memset(last2,-1,sizeof(last2));
        sort(ad2,ad2+len2);
        for(int i=0;i<len2;i++){
            if(first2[ad2[i]-'a']==-1)first2[ad2[i]-'a']=i;
            last2[ad2[i]-'a']=i;
        }

        int X;
        scanf("%d",&X);

        if(X>500)printf("Case %d: 0\n",test);
        else{
            memset(store1,-1,sizeof(store1));
            memset(store2,-1,sizeof(store2));

            LL ans=0;
            for(int i=0;i<=X;i++)if(i<=250 && X-i<=250){
                ans=ans+ways1(i,0,0)*ways2(X-i,0,1);
                ans=ans+ways1(i,0,1)*ways2(X-i,0,0);
            }
            printf("Case %d: %lld\n",test,ans);
        }
    }
}
