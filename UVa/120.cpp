#include<bits/stdc++.h>
using namespace std;

int pancakes[101],sorted[101];

int main()
{
    string text;
    while(getline(cin,text)){
        int n=0;

        int x;
        istringstream iss (text);
        while(iss>>pancakes[++n]);
        n--;
        for(int i=1;i<n;i++)cout<<pancakes[i]<<" ";
        cout<<pancakes[n]<<"\n";

        for(int i=1;i<=n;i++)sorted[i]=pancakes[i];
        sort(sorted+1,sorted+n+1);

        bool complete=true;
        for(int i=2;i<=n;i++)if(pancakes[i]<pancakes[i-1])complete=false;

        while(!complete){
            int counter=n;
            while(pancakes[counter]==sorted[counter])counter--;

            int idx;
            for(int i=counter-1;i>=1;i--)if(pancakes[i]==sorted[counter]){
                idx=i;
                break;
            }
            if(idx!=1){
                cout<<n-idx+1<<" ";
                int temp[101];

                int c=1;
                for(int i=idx;i>=1;i--,c++)temp[c]=pancakes[i];
                for(int i=idx;i>=1;i--)pancakes[i]=temp[i];
            }

            cout<<n-counter+1<<" ";
            int temp[101];

            int c=1;
            for(int i=counter;i>=1;i--,c++)temp[c]=pancakes[i];
            for(int i=counter;i>=1;i--)pancakes[i]=temp[i];

            complete=true;
            for(int i=2;i<=n;i++)if(pancakes[i]<pancakes[i-1])complete=false;
        }
        cout<<"0\n";
    }
}
