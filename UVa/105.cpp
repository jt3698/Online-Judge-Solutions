#include<bits/stdc++.h>
using namespace std;

int heights[10005];

int main()
{
    int max_R=0;
    int L,R,H;
    while(cin>>L){
        cin>>H>>R;
        max_R=max(max_R,R);
        for(int i=L;i<R;i++)heights[i]=max(heights[i],H);
    }
    int cur_height=0;

    for(int i=1;i<max_R;i++){
        if(heights[i]>cur_height)printf("%d %d ",i,heights[i]);
        if(heights[i]<cur_height)printf("%d %d ",i,heights[i]);
        cur_height=heights[i];
    }
    printf("%d 0\n",max_R);
}
