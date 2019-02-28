#include<bits/stdc++.h>
using namespace std;

int order[1001];
int stacking[1001],idx=0;

int main()
{
    int N;
    scanf("%d",&N);
    while(N!=0){
        scanf("%d",&order[1]);
        while(order[1]!=0){
            for(int i=2;i<=N;i++)scanf("%d",&order[i]);

            idx=0;
            int currently=1;
            for(int i=1;i<=N;i++){
                stacking[++idx]=i;
                while(idx>0 && stacking[idx]==order[currently]){
                    idx--;
                    currently++;
                }
            }
            if(currently==N+1)printf("Yes\n");
            else printf("No\n");

            scanf("%d",&order[1]);
        }

        printf("\n");
        scanf("%d",&N);
    }
}
