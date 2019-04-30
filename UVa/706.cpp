#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s,N;
    scanf("%d %d",&s,&N);
    while(s!=0 || N!=0){
        int digits[10];
        int digit_count=0;

        int temp=N;
        while(temp>0){
            digit_count++;
            temp/=10;
        }
        if(N==0){
            digit_count=1;
            digits[1]=0;
        }
        else{
            temp=N;
            for(int i=digit_count;i>=1;i--){
                digits[i]=temp%10;
                temp/=10;
            }
        }

        for(int i=1;i<=digit_count;i++){
            if(i>1)printf(" ");
            printf(" ");

            if(digits[i]==1 || digits[i]==4)for(int i=1;i<=s;i++)printf(" ");
            else for(int i=1;i<=s;i++)printf("-");

            printf(" ");
        }
        printf("\n");

        for(int r=1;r<=s;r++){
            for(int i=1;i<=digit_count;i++){
                if(i>1)printf(" ");

                if(digits[i]==1 || digits[i]==2 || digits[i]==3 || digits[i]==7)printf(" ");
                else printf("|");

                for(int i=1;i<=s;i++)printf(" ");

                if(digits[i]==5 || digits[i]==6)printf(" ");
                else printf("|");
            }
            printf("\n");
        }

        for(int i=1;i<=digit_count;i++){
            if(i>1)printf(" ");
            printf(" ");

            if(digits[i]==1 || digits[i]==7 || digits[i]==0)for(int i=1;i<=s;i++)printf(" ");
            else for(int i=1;i<=s;i++)printf("-");

            printf(" ");
        }
        printf("\n");

        for(int r=1;r<=s;r++){
            for(int i=1;i<=digit_count;i++){
                if(i>1)printf(" ");

                if(digits[i]==2 || digits[i]==6 || digits[i]==8 || digits[i]==0)printf("|");
                else printf(" ");

                for(int i=1;i<=s;i++)printf(" ");

                if(digits[i]==2)printf(" ");
                else printf("|");
            }
            printf("\n");
        }

        for(int i=1;i<=digit_count;i++){
            if(i>1)printf(" ");
            printf(" ");

            if(digits[i]==1 || digits[i]==4 || digits[i]==7)for(int i=1;i<=s;i++)printf(" ");
            else for(int i=1;i<=s;i++)printf("-");

            printf(" ");
        }
        printf("\n");

        printf("\n");

        scanf("%d %d",&s,&N);
    }
}
