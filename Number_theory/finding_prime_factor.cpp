#include<iostream>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

#define MAX 10000000

void Gen_prime(void);
bool sieve[MAX+1];
vector<int>prime;

map<long long int,long long int>prime_fact;
map<long long int,long long int>::iterator it;

void Gen_prime(void)
{

    unsigned long long int num;

    static unsigned long long int i,j;
    for(i=4;i<=MAX;i+=2)
        sieve[i]=1;
    for(i=3;i*i<=MAX;i+=2)
    {
        if(sieve[i]==0)
            for(j=i*i;j<=MAX;j=2*i+j)
            sieve[j]=1;
    }
    prime.push_back(2);
    for(int i=3;i<=MAX;i+=2)
    {
        if(sieve[i]==0)
            prime.push_back(i);
    }
}

int Gen_prime_fact(long long int num)
{

  int i=0;
    while(num!=1 && prime[i]<=sqrt(num))
   {
       while(num%prime[i]==0)
       {
           prime_fact[prime[i]]++;
           num=num/prime[i];
       }


       i++;

   }
   if(num!=1)
   {
       prime_fact[num]++;
   }

}

int main()
{
    long long int num;


    Gen_prime();
    while(1)
    {
     cin>>num;
      Gen_prime_fact(num);
    {
        for(it=prime_fact.begin();it!=prime_fact.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }

        prime_fact.clear();
    }
    }


}
