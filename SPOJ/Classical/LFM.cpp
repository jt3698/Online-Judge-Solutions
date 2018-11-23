#include<bits/stdc++.h>
using namespace std;

map<string,int>address;
vector<int>connections[101];
int material[101];
int depend_no[101],depend_id[101];
int counter;
char c;

int valid(int x)
{
    int res=0;
    for(int i=0;i<=counter;i++)if(x & (1<<i)){
        res+=material[depend_id[i]];
        for(int o=0;o<connections[depend_id[i]].size();o++){
            int need=depend_no[connections[depend_id[i]][o]];
            if(!(x & (1<<need)))return -1;
        }
    }
    return res;
}

int main()
{
    int M,D;
    scanf("%d",&M);
    while(M!=0){
        scanf("%d\n",&D);
        for(int i=1;i<=M;i++){
            string temp="";
            c=getchar();
            while(c!='\n' && c!=' '){
                temp+=c;
                c=getchar();
            }
            address[temp]=i;
            scanf("%d\n",&material[i]);

            connections[i].clear();
            depend_no[i]=-1;
        }
        counter=-1;
        for(int i=1;i<=D;i++){
            string a="",b="";
            c=getchar();
            while(c!='\n' && c!=' '){
                a+=c;
                c=getchar();
            }
            c=getchar();
            while(c!='\n' && c!=' '){
                b+=c;
                c=getchar();
            }
            int A=address[a];
            int B=address[b];

            if(depend_no[A]==-1){
                depend_no[A]=++counter;
                depend_id[counter]=A;
            }
            if(depend_no[B]==-1){
                depend_no[B]=++counter;
                depend_id[counter]=B;
            }

            connections[A].push_back(B);
        }
        vector<int>greedy;
        for(int i=1;i<=M;i++)if(depend_no[i]==-1)greedy.push_back(material[i]);
        sort(greedy.begin(),greedy.end());

        int topic=0;
        int ans=0;
        for(int i=0;i<(1<<(counter+1));i++){
            int temp=valid(i);
            int temp_topic=0;
            if(temp!=-1 && temp<=250){
                temp_topic=__builtin_popcount(i);
                for(int i=0;i<greedy.size() && temp+greedy[i]<=250;i++){
                    temp+=greedy[i];
                    temp_topic++;
                }
            }
            if(temp_topic>topic){
                topic=temp_topic;
                ans=temp;
            }
            else if(temp_topic==topic && temp<ans && temp!=-1)ans=temp;
        }

        printf("%d %d\n",topic,250-ans);

        scanf("%d",&M);
    }
}
