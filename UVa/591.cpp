#include<bits/stdc++.h>
using namespace std;

int sequence[51];

int main()
{
    int test=0;

    int N;
    scanf("%d",&N);
    while(N!=0){
        test++;
        int sum=0;
        for(int i=1;i<=N;i++){
            scanf("%d",&sequence[i]);
            sum+=sequence[i];
        }
        int height=sum/N;

        int answer=0;
        for(int i=1;i<=N;i++)if(sequence[i]>height)answer+=(sequence[i]-height);
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",test,answer);

        scanf("%d",&N);
    }

    return 0;
}
