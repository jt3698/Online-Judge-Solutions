#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int test=1;test<=T;test++){
        char piece='\n';int M,N;
        while(piece=='\n')cin>>piece;
        cin>>M>>N;
        if(piece=='r' || piece=='Q')cout<<min(M,N)<<endl;
        else if(piece=='k')cout<<M*N/2+M*N%2<<endl;
        else cout<<(M/2+M%2)*(N/2+N%2)<<endl;
    }
}
