#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    int boxes[26][26];
    int max_index[26];
    pair<int,int>location[26];
    for(int i=0;i<N;i++){
        boxes[i][1]=i;
        max_index[i]=1;
        location[i]=make_pair(i,1);
    }

    string command;
    cin>>command;
    while(command!="quit"){
        int A,B;
        scanf("%d",&A);
        string command_2;
        cin>>command_2;
        scanf("%d",&B);

        if(location[A].first!=location[B].first){
            bool illegal=false;
            if(command=="move"){
                if(command_2=="onto"){
                    for(int i=location[A].second+1;i<=max_index[location[A].first];i++){
                        int temp_box=boxes[location[A].first][i];
                        if(temp_box==location[A].first || temp_box==location[B].first)illegal=true;
                    }
                     for(int i=location[B].second+1;i<=max_index[location[B].first];i++){
                        int temp_box=boxes[location[B].first][i];
                        if(temp_box==location[A].first || temp_box==location[B].first)illegal=true;
                    }
                    if(!illegal){
                        for(int i=location[A].second+1;i<=max_index[location[A].first];i++){
                            int temp_box=boxes[location[A].first][i];
                            boxes[temp_box][++max_index[temp_box]]=temp_box;
                            location[temp_box]=make_pair(temp_box,max_index[temp_box]);
                        }
                        for(int i=location[B].second+1;i<=max_index[location[B].first];i++){
                            int temp_box=boxes[location[B].first][i];
                            boxes[temp_box][++max_index[temp_box]]=temp_box;
                            location[temp_box]=make_pair(temp_box,max_index[temp_box]);
                        }
                        boxes[location[B].first][location[B].second+1]=A;
                        max_index[location[B].first]=location[B].second+1;
                        max_index[location[A].first]=location[A].second-1;
                        location[A]=make_pair(location[B].first,location[B].second+1);
                    }
                }
                else{
                    for(int i=location[A].second+1;i<=max_index[location[A].first];i++){
                        int temp_box=boxes[location[A].first][i];
                        if(temp_box==location[A].first)illegal=true;
                    }
                    if(!illegal){
                        for(int i=location[A].second+1;i<=max_index[location[A].first];i++){
                            int temp_box=boxes[location[A].first][i];
                            boxes[temp_box][++max_index[temp_box]]=temp_box;
                            location[temp_box]=make_pair(temp_box,max_index[temp_box]);
                        }
                        boxes[location[B].first][++max_index[location[B].first]]=A;
                        max_index[location[A].first]=location[A].second-1;
                        location[A]=make_pair(location[B].first,max_index[location[B].first]);
                    }
                }
            }
            else{
                if(command_2=="onto"){
                     for(int i=location[B].second+1;i<=max_index[location[B].first];i++){
                        int temp_box=boxes[location[B].first][i];
                        if(temp_box==location[B].first)illegal=true;
                    }
                    if(!illegal){
                        for(int i=location[B].second+1;i<=max_index[location[B].first];i++){
                            int temp_box=boxes[location[B].first][i];
                            boxes[temp_box][++max_index[temp_box]]=temp_box;
                            location[temp_box]=make_pair(temp_box,max_index[temp_box]);
                        }
                        max_index[location[B].first]=location[B].second;
                        int original=location[A].first;
                        int become=location[A].second-1;
                        for(int i=location[A].second;i<=max_index[original];i++){
                            int temp_box=boxes[original][i];
                            boxes[location[B].first][++max_index[location[B].first]]=temp_box;
                            location[temp_box]=make_pair(location[B].first,max_index[location[B].first]);
                        }
                        max_index[original]=become;
                    }
                }
                else{
                    if(!illegal){
                        int original=location[A].first;
                        int become=location[A].second-1;
                        for(int i=location[A].second;i<=max_index[original];i++){
                            int temp_box=boxes[original][i];
                            boxes[location[B].first][++max_index[location[B].first]]=temp_box;
                            location[temp_box]=make_pair(location[B].first,max_index[location[B].first]);
                        }
                        max_index[original]=become;
                    }
                }
            }
        }

        cin>>command;
    }

    for(int i=0;i<N;i++){
        printf("%d:",i);
        for(int o=1;o<=max_index[i];o++)printf(" %d",boxes[i][o]);
        printf("\n");
    }
}
