#include<stdio.h>

int main()
{
    int answer[100000];
    int index=0;
    int hour,minute;
    scanf("%d:%d",&hour,&minute);
    while(hour!=0){
        if(hour==12)hour=0;
        int total_minutes=60*hour+minute;
        if(total_minutes>=minute*12)answer[++index]=total_minutes-minute*12;
        else answer[++index]=minute*12-total_minutes;
        scanf("%d:%d",&hour,&minute);
    }
    for(int i=1;i<=index;i++){
            if(answer[i]<=360)printf("%.3f\n",(float)answer[i]/2);
            else printf("%.3f\n",360-(float)answer[i]/2);
        }
}
