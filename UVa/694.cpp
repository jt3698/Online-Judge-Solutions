#include<bits/stdc++.h>
#define LL long long int
using namespace std;

int main()
{
    int test=0;
    LL A,B;
    scanf("%lld %lld",&A,&B);
    while(A>=0 || B>=0){
        test++;
        LL ori=A;
        LL ans=1;
        while(A<=B && A!=1){
            if(A%2==0)A/=2;
            else A=A*3+1;
            ans++;
        }
        if(A>B)ans--;
        printf("Case %d: A = %lld, limit = %lld, number of terms = %lld\n",test,ori,B,ans);

        scanf("%lld %lld",&A,&B);
    }
}
