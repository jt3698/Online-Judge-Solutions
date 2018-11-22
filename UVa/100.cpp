#include<bits/stdc++.h>
using namespace std;

int collatz(int x)
{
    int counter=1;
    while(x!=1){
        if(x%2==0)x=x/2;
        else x=3*x+1;
        counter++;
    }
    return counter;
}

int main()
{
    int A,B;
    while(cin>>A>>B){

        int original_A=A,original_B=B;
        if(A>B)swap(A,B);

        int largest=0;
        for(;A<=B;A++)
            if(collatz(A)>largest)largest=collatz(A);

        cout<<original_A<<" "<<original_B<<" "<<largest<<"\n";
    }

    return 0;
}
