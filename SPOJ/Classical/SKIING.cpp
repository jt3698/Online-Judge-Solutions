#include<bits/stdc++.h>
using namespace std;

pair<double,double>racers[400];
vector<double>intervals;

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%lf %lf",&racers[i].first,&racers[i].second);
        intervals.push_back(racers[i].first);
        intervals.push_back(racers[i].second);
    }
    sort(intervals.begin(),intervals.end());
    double ans=0;
    for(int i=0;i<intervals.size()-1;i++){
        double s=intervals[i];
        double e=intervals[i+1];
        double ABCD=racers[1].second-racers[1].first;
        if(s>=racers[1].first && e<=racers[1].second){
            int counter=1;
            double xyz[301];
            double prob=0;
            bool can=true;
            for(int o=2;o<=N && can;o++){
                if(racers[o].second<=s)can=false;
                else if(racers[o].first<e){
                    xyz[counter]=racers[o].second-e;
                    counter++;
                    ABCD*=(racers[o].second-racers[o].first);
                }
            }
            if(can){
                double combinations[301][301];
                counter--;
                combinations[1][counter]=xyz[counter];
                for(int j=counter-1;j>=1;j--)combinations[1][j]=combinations[1][j+1]+xyz[j];
                for(int x=2;x<=counter;x++){
                    combinations[x][counter-x+2]=0;
                    for(int j=counter-x+1;j>=1;j--)combinations[x][j]=combinations[x][j+1]+combinations[x-1][j+1]*xyz[j];
                }
                double T=e-s;
                double front_part=T/ABCD;
                for(int x=counter;x>=1;x--){
                    prob+=front_part*(combinations[x][1]);
                    front_part*=T;;
                    front_part*=(counter-x+1);
                    front_part/=(counter-x+2);
                }
                prob+=front_part;
                ans+=prob;
            }
        }
    }
    printf("%.7lf\n",ans);

}
