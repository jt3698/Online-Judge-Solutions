#include<bits/stdc++.h>
using namespace std;

int position[51];

int main()
{
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        int L;
        scanf("%d",&L);

        int counter=0;
        for(int i=1;i<=L;i++)scanf("%d",&position[i]);

        for(int i=1;i<=L;i++){
            int temp;
            for(int o=i;o<=L;o++)if(position[o]==i)temp=o;

            counter+=(temp-i);
            for(int o=temp-1;o>=i;o--)position[o+1]=position[o];
            position[i]=i;
        }

        printf("Optimal train swapping takes %d swaps.\n",counter);
    }

    return 0;
}
