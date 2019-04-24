#include<bits/stdc++.h>
using namespace std;

vector<string>store;

int main()
{
    int test=0;
    string temp;
    while(cin>>temp){
        store.clear();
        test++;
        while(temp!="9"){
            store.push_back(temp);
            cin>>temp;
        }
        bool immediate=true;
        for(int i=0;i<store.size() && immediate;i++)for(int j=0;j<store.size() && immediate;j++)if(i!=j){
            bool prefix=true;
            for(int o=0;o<store[i].size();o++){
                if(o>=store[j].size()){
                    prefix=false;
                    break;
                }
                else{
                    if(store[i][o]!=store[j][o]){
                        prefix=false;
                        break;
                    }
                }
            }
            if(prefix)immediate=false;
        }
        if(immediate)printf("Set %d is immediately decodable\n",test);
        else printf("Set %d is not immediately decodable\n",test);
    }
}
