#include<iostream>
#include<stdio.h>
#include<cmath>
#define MAX 10000001
using namespace std;
void Gen_prime(void);
bool sieve[MAX];
long long int Prime_fact[10000001];
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

  for(int k=num;k>1;k--)

  {
      temp=k;

   while(temp%2==0)
        {

            Prime_fact[2]++;
            temp=temp/2;
        }

    for(i=3;i*i<=num && sieve[temp];)
        {
        if(sieve[i]==0)

        if(temp%i==0)
         {
          Prime_fact[i]++;
          temp=temp/i;
         }
         else
            i=i+2;
        else
            i=i+2;

         }

    if(sieve[temp]==0 && temp!=1)
        {
         Prime_fact[temp]++;
        }

  }

}


int Gen_prime_f(long long int num)
{

  long long int temp,i,j;

     temp=num;

   while(temp%2==0)
        {

            Prime_fact[2]++;
            temp=temp/2;
        }

    for(i=3;i*i<=num && sieve[temp];)
        {
        if(sieve[i]==0)

        if(temp%i==0)
         {
          Prime_fact[i]++;
          temp=temp/i;
         }
         else
            i=i+2;
        else
            i=i+2;

         }

    if(sieve[temp]==0 && temp!=1)
        {
         Prime_fact[temp]++;
        }



}




int main()
{
    long int N,M,i,j,k,n[10000001],m[10000001],nm[10000001],ans=1;

    Gen_prime();

    while(cin>>N>>M &&(N!=0 && M!=0))
    {
       ans=1;


       for(i=2;i<100;i++)
        n[i]=m[i]=nm[i]=0;



       Gen_prime_fact(N);

       for(i=2;i<100;i++)
        n[i]=Prime_fact[i];

        for(i=2;i<100;i++)
            Prime_fact[i]=0;




         Gen_prime_fact(N-M);

       for(i=2;i<100;i++)
         nm[i]=Prime_fact[i];


        for(i=2;i<100;i++)
            Prime_fact[i]=0;



             Gen_prime_fact(M);

       for(i=2;i<100;i++)
        m[i]=Prime_fact[i];

        for(i=2;i<100;i++)
            Prime_fact[i]=0;




            for(i=2;i<100;i++)
                n[i]=n[i]-m[i]-nm[i];


         for(i=2;i<100;i++)
         {

             if(n[i]>0)
             {

                 ans=ans*power(i,n[i]);
             }
         }
         cout<<N<<" things taken "<<M<<" at a time is "<<ans<<" exactly."<<endl;


    }
   return 0;
}



