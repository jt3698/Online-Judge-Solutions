#include<bits/stdc++.h>
using namespace std;

int main()
{
    string id;
    cin>>id;
    while(id!="#"){
        vector<int>id_number;
        for(int i=0;i<id.length();i++)id_number.push_back(id[i]-'a');

        if(next_permutation(id_number.begin(),id_number.end())){
            for(int i=0;i<id_number.size();i++)printf("%c",id_number[i]+'a');
            printf("\n");
        }
        else printf("No Successor\n");

        cin>>id;
    }

    return 0;
}
