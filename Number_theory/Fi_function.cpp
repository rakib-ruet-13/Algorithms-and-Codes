#include<bits\stdc++.h>
#define MAX 10000000
using namespace std;
void Gen_prime(void);
bool sieve[MAX];

map<long int,long int>prime_fact;
map<long int,long int>::iterator it;

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
}

int Gen_prime_fact(long long int num)
{

  long long int temp,i,j;
  temp=num;

   while(temp%2==0)
        {

            prime_fact[2]++;
            temp=temp/2;
        }

    for(i=3;i*i<=num && sieve[temp];)
        {
        if(sieve[i]==0)

        if(temp%i==0)
         {
          prime_fact[i]++;
          temp=temp/i;
         }
         else
            i=i+2;
        else
            i=i+2;

         }

    if(sieve[temp]==0 && temp!=1)
        {
         prime_fact[temp]++;
        }


}


long long power(long int num,long int base)
{
    long long int ans=1;
    if(base==0)
        return 1;
    for(int i=1;i<=base;i++)
        ans=ans*num;
    return ans;



}

long long int fi_funtion(int num)
{
    long int ans=1;

       if(num==1)
        return 0;

       if(sieve[num]==0)
        return num-1;

       else
       {

            Gen_prime_fact(num);
         {
            for(it=prime_fact.begin();it!=prime_fact.end();it++)
           {
             ans*=power(it->first,it->second)-power(it->first,it->second-1);
           }

        prime_fact.clear();
        }

       }

       return ans;

}

int main()
{
    long long int num;


    Gen_prime();
    while(1)
    {
     cin>>num;
     cout<<fi_funtion(num)<<endl;

    }


}

