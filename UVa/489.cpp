#include<bits/stdc++.h>
using namespace std;

int main()
{
    int answers[100000];
    int T;
    scanf("%d",&T);
    while(T!=-1){
        bool distinct[10000];
        memset(distinct,false,sizeof(distinct));
        int distinct_index=0;

        char word[100000],answer[100000];
        scanf("%s",word);
        scanf("%s",answer);

        for(int i=0;i<strlen(word);i++)if(!distinct[word[i]]){distinct[word[i]]=true;distinct_index++;}

        int wrong=0;

        bool distinct_answer[10000];
        memset(distinct_answer,false,sizeof(distinct_answer));
        int distinct_answer_index=0;char answer_letters[10000];

        for(int i=0;i<strlen(answer);i++)if(!distinct_answer[answer[i]]){distinct_answer[answer[i]]=true;answer_letters[++distinct_answer_index]=answer[i];}

        for(int i=1;i<=distinct_answer_index && distinct_index>0;i++){
            if(distinct[answer_letters[i]])distinct_index--;
            else wrong++;

            if(wrong==7)break;
        }
        if(wrong==7)printf("Round %d\nYou lose.\n",T);
        else if(distinct_index==0)printf("Round %d\nYou win.\n",T);
        else printf("Round %d\nYou chickened out.\n",T);

        scanf("%d",&T);
    }
}

