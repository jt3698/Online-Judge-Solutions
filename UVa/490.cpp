#include<bits/stdc++.h>
using namespace std;

int printing[200][200];

int main()
{
    vector<string>text;
    string temp;
    while(getline(cin,temp))text.push_back(temp);

    int furthest_for_line=-1;
    int maximum=-1;
    memset(printing,-1,sizeof(printing));
    for(int x=0;x<text.size();x++){
        maximum=max(maximum,(int)text[x].size());
        for(int y=0;y<text[x].size();y++){
            furthest_for_line=max(furthest_for_line,(int)text.size()-1-x);
            printing[y][text.size()-1-x]=text[x][y];
        }
    }
    for(int y=0;y<maximum;y++){
        for(int x=0;x<=furthest_for_line;x++)
            if(printing[y][x]==-1)printf(" ");
            else printf("%c",printing[y][x]);
        printf("\n");
    }
}
