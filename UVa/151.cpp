#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans[101];
    bool off[101];
    for(int i=13;i<=100;i++){
        for(int m=1;m<=i;m++){
            memset(off,false,sizeof(off));
            int counter=m-1,how_many_off=0;
            int where=1;
            while(!off[13]){
                if(!off[where]){
                    counter++;
                    if(counter==m){
                        off[where]=true;
                        how_many_off++;
                        counter=0;
                    }
                }

                where%=i;
                where++;
            }
            if(how_many_off==i){
                ans[i]=m;
                break;
            }
        }
    }

    int N;
    scanf("%d",&N);
    while(N!=0){
        printf("%d\n",ans[N]);
        scanf("%d",&N);
    }
}
