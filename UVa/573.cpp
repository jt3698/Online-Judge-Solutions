#include<bits/stdc++.h>
using namespace std;

int main()
{
    double height,climbing,falling,fatigue;
    cin>>height>>climbing>>falling>>fatigue;
    while(height!=0){
        fatigue=climbing*fatigue/100;
        int day_now=0;
        double height_now=0;
        while((height_now>=0 && height_now<=height) || day_now==0){
            if(day_now>0)height_now-=falling;
            day_now++;
            height_now+=climbing;
            climbing-=fatigue;
            climbing=max(0.0,climbing);
            if(height_now<=height && height_now-falling<0)break;
        }
        if(height_now-falling<0)printf("failure on day %d\n",day_now);
        else printf("success on day %d\n",day_now);

        cin>>height>>climbing>>falling>>fatigue;
    }
}
