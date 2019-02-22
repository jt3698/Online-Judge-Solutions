#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>character_counts[1001];
    string text[1001];
    int counter=0;
    cin>>text[counter+1];
    while(text[counter+1]!="#"){
        counter++;
        for(int i=0;i<text[counter].length();i++){
            if(text[counter][i]>='a' && text[counter][i]<='z')character_counts[counter].push_back(text[counter][i]-'a'+1);
            if(text[counter][i]>='A' && text[counter][i]<='Z')character_counts[counter].push_back(text[counter][i]-'A'+1);
        }
        sort(character_counts[counter].begin(),character_counts[counter].end());
        cin>>text[counter+1];
    }
    vector<string>answer;
    for(int i=1;i<=counter;i++){
        bool ananagram=true;
        for(int j=1;j<=counter && ananagram;j++)if(j!=i && character_counts[i]==character_counts[j])ananagram=false;
        if(ananagram)answer.push_back(text[i]);
    }
    sort(answer.begin(),answer.end());
    for(int i=0;i<answer.size();i++)cout<<answer[i]<<endl;
}
