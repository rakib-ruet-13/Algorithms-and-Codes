#include<iostream>
#include<bits/stdc++.h>
#define Max 10000010
#define pb(x) push_back(x)


using namespace std;

bool sieve[Max+1];
vector<int > prime;


void Gen_prime()
{
    for(int i=4; i<=Max;i+=2)
        sieve[i]=1;
    for(int i=3; i<=sqrt(Max);i+=2)
    {
        if(!sieve[i])
            for(int j=i*i ;j<=Max;j+=2*i)
                sieve[j]=1;
    }
    prime.pb(2);
    for(int i=3 ;i<=Max ;i+=2)
    {
        if(!sieve[i])
            prime.pb(i);
    }

}

int main()
{


    int tc,n;

    Gen_prime();

    scanf("%d",&tc);
    for(int cs=1 ; cs<= tc; cs++)
    {
        scanf("%d",&n);

        int cnt=0;

        for(int i=0 ; prime[i]<= n/2 ; i++)
        {
            if(! sieve[ n - prime[i] ])
             {
                 cnt++;
             }
        }

        printf("Case %d: %d\n",cs,cnt);

    }






}
