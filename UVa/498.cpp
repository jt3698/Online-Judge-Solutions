#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL coefficients[100001];
LL x_s[100001];

int main()
{
    string coeff,x;
    while(getline(cin,coeff)){
        getline(cin,x);

        istringstream temp(coeff);
        int counter1=0;

        LL co;
        while(temp>>co){
            counter1++;
            coefficients[counter1]=co;
        }
        for(int i=1;i<=counter1/2;i++)swap(coefficients[i],coefficients[counter1+1-i]);

        istringstream temp2(x);
        int counter2=0;

        LL x_temp;
        while(temp2>>x_temp){
            counter2++;
            x_s[counter2]=x_temp;
        }


        for(int i=1;i<=counter2;i++){
            if(i>1)printf(" ");

            LL sum=0,cur_x=1;
            for(int j=1;j<=counter1;j++){
                sum+=coefficients[j]*cur_x;
                cur_x*=x_s[i];
            }
            printf("%lld",sum);
        }
        printf("\n");
    }
}
