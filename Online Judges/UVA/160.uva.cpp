#include<iostream>
#include<stdio.h>
#define MAX 101
using namespace std;
void Gen_prime(void);
bool sieve[MAX];
long long int Prime_fact[101];
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

int main()
{
    long long int num,cs,cnt,i;

    Gen_prime();

    while(cin>>num)
    {
        if(num==0)
            break;
       cnt=0;
       Gen_prime_fact(num);

       printf("%3lld! =",num);

       cs=0;
       for(i=2;i<100;i++)
       {
           if(Prime_fact[i]>0)
           cs++;
       }

       for(i=2;i<100;i++)
       {
           if(cnt==15 && cs>15)
            {
                cout<<"\n      ";
                cnt++;
            }
           if(Prime_fact[i]>0)
            {printf("%3lld",Prime_fact[i]);
            cnt++;
            }
       }
       printf("\n");

       for(i=2;i<100;i++)
        Prime_fact[i]=0;
    }
   return 0;
}

