#include<bits/stdc++.h>
#define LL long long
using namespace std;

int ranking[21];
int sequences[21],len;

int main()
{
    int found=0;
    string text;
    int n,ans;
    while(getline(cin,text)){
        if(text.size()<=2){
            istringstream temp(text);
            temp>>n;
            found=1;
        }
        else if(found==1){
            istringstream temp(text);
            for(int i=1;i<=n;i++){
                int r;
                temp>>r;
                ranking[r]=i;
            }
            found=2;
        }
        else{
            istringstream temp(text);
            int student[21];
            for(int i=1;i<=n;i++)temp>>student[i];

            int new_list[21];
            for(int i=1;i<=n;i++)new_list[i]=student[ranking[i]];

            len=1;
            sequences[len]=new_list[1];
            for(int i=2;i<=n;i++){
                if(new_list[i]>sequences[len])sequences[++len]=new_list[i];
                else{
                    int l=1,r=len;
                    int put_in;
                    while(l<=r){
                        int mid=(l+r)/2;
                        if(sequences[mid]>new_list[i]){
                            put_in=mid;
                            r=mid-1;
                        }
                        else l=mid+1;
                    }
                    sequences[put_in]=new_list[i];
                }
            }
            printf("%d\n",len);
        }
    }
}
