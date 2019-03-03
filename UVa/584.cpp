#include<bits/stdc++.h>
using namespace std;

int main()
{
    string score_card;
    getline(cin,score_card);
    while(score_card!="Game Over"){
        int total_score=0;

        int each_frame_score[15];
        int frame=1;int counter=1;
        each_frame_score[frame]=0;
        for(int i=0;i<score_card.length();i++){
            if(score_card.at(i)=='X'){
                each_frame_score[frame]=10;
                frame++;
                each_frame_score[frame]=0;
            }
            if(score_card.at(i)>='0' && score_card.at(i)<='9'){each_frame_score[frame]+=score_card.at(i)-'0';counter++;}
            else if(counter==2 && score_card.at(i)=='/'){
                each_frame_score[frame]=10;
                counter++;
            }

            if(counter==3){
                frame++;
                each_frame_score[frame]=0;
                counter=1;
            }
        }

        for(int i=1;i<=10;i++)total_score+=each_frame_score[i];

        for(int i=0;i<score_card.length();i++){
            if(score_card.at(i)=='X'){
                if(i+4<score_card.length()){
                    if(score_card.at(i+4)=='X')total_score+=10;
                    else if(score_card.at(i+4)=='/')total_score+=(10-score_card.at(i+2)+'0');
                    else total_score+=score_card.at(i+4)-'0';
                }
                if(i-2>=0){
                    if(i+2<score_card.length() && !(score_card.at(i-2)=='X' && i+2==score_card.length()-1)){
                        if(score_card.at(i+2)=='X')total_score+=10;
                        else total_score+=score_card.at(i+2)-'0';
                    }
                }
                else{
                    if(i+2<score_card.length()){
                        if(score_card.at(i+2)=='X')total_score+=10;
                        else total_score+=score_card.at(i+2)-'0';
                    }
                }
            }
            else if(score_card.at(i)=='/'){
                if(i+2<score_card.length()){
                    if(score_card.at(i+2)=='X')total_score+=10;
                    else total_score+=score_card.at(i+2)-'0';
                }
            }
        }
        cout<<total_score<<endl;

        getline(cin,score_card);
    }
}
