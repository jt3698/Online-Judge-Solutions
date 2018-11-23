#include<bits/stdc++.h>
#define LL long long int
using namespace std;

LL prime_list[80001];
bool prime[100001];
int prime_counter=0;
void sieve()
{
    int lim=100000;
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    for(int i=2;i*i<=lim;i++)if(prime[i])for(int o=i*i;o<=lim;o+=i)prime[o]=false;
    for(int i=2;i<=lim;i++)if(prime[i])prime_list[++prime_counter]=(LL)i;
    return;
}

LL mulmod(LL aaa, LL bbb, LL modu){
    if(bbb==0)return 0;
    LL temp=mulmod(aaa,bbb/2,modu)%modu;
    temp=temp*2;
    temp%=modu;
    if(bbb%2==1)temp+=aaa;
    return temp%modu;
}

LL powof(LL dasar, LL expo,LL modu){
    if(expo==0) return 1;
    else{
        LL tmp = powof(dasar,expo/2,modu);
        if(modu<=1000000000){
        	tmp %= modu;
        	tmp *= tmp;
        	tmp %= modu;
        	if(expo%2==1) tmp *= dasar;
        	tmp %= modu;
       		return tmp;
    	}else{
    		tmp = mulmod(tmp,tmp,modu);
    		if(expo%2==1) tmp = mulmod(tmp,dasar,modu);
    		return tmp;
    	}
    }
}

bool millerTest(LL d, LL num)
{
    LL a = 2 + rand() % (num - 4);
    LL x = powof(a,d,num);
    if (x == 1 ||x == num-1)
       return 1;
    while (d != num-1){
        x = mulmod(x,x,num);
        d *= 2;
        if (x == 1) return 0;
        if (x == num-1)return 1;
    }
    return 0;
}

bool isPrime(LL num)
{
    if(num<=1 || num==4)return false;
    if(num<=3) return true;
    LL d=num-1;
    while(d%2==0)d/=2;
    for(int i=1;i<=30;i++)if(!millerTest(d,num))return false;
    return true;
}

int main()
{
    sieve();
    srand(time(NULL));
    int T;
    scanf("%d",&T);
    for(int test=1;test<=T;test++){
        LL N,s=-1;
        scanf("%lld",&N);
        LL ori=N;

        LL ans=1;
        for(int i=1;i<=prime_counter && N>1;i++){
            if(N<prime_list[i])break;
            LL temp=1;
            while(N%prime_list[i]==0){
                N/=prime_list[i];
                temp++;
            }
            ans=ans*temp;
        }
        LL square_root=floor(sqrt(N));
        if(N>1){
            if(square_root*square_root==N)ans*=3;
            else if(isPrime(N))ans*=2;
            else ans*=4;
        }

        if(ans%2==0)printf("%lld\n",powof(ori,ans/2,1000000007));
        else printf("%lld\n",powof(floor(sqrt(ori)),ans,1000000007));
    }
}
