#include<bits/stdc++.h>
using namespace std;

bool prime[1000001];
int less_than=1000000;
vector<int>primes;

void sieve()
{
    prime[1]=false;
    for(int i=1;i*i<=less_than;i++)if(prime[i])for(int o=i*i;o<=less_than;o+=i)prime[o]=false;
    for(int i=1;i<=less_than;i++)if(prime[i])primes.push_back(i);
}

int main()
{
    memset(prime,true,sizeof(prime));
    sieve();
    int number;
    scanf("%d",&number);
    while(number!=0){
        int counter=0;

        int left=0,right=primes.size()-1;
        while(left<=right){
            if(primes[left]+primes[right]==number){
                counter++;
                left++;
                right--;
            }
            else if(primes[left]+primes[right]>number)right--;
            else left++;
        }
        printf("%d\n",counter);

        scanf("%d",&number);
    }
}

