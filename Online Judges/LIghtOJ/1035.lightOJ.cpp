#include<iostream>
#include<algorithm>
#include<cmath>
#define MAX 1000
using namespace std;
void Gen_prime(void);
bool sieve[MAX];
long long int Prime_fact[127];
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

void Gen_prime_fact(long long int num)
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
    Gen_prime();
   long long int num,i,tc,cs=0,flag;

   cin>>tc;

   while (tc--)
   {
       flag=0;
       cin>>num;
       for(i=num;i>1;i--)
       {
           Gen_prime_fact(i);
       }
       cout<<"Case "<<++cs<<": "<<num<<" = ";
       for(i=2;i<=num;i++)
       {
           if(Prime_fact[i]!=0 && sieve[i]==0)
           {
               if(flag==0)
               {
                   cout<<i<<" ("<<Prime_fact[i]<<")";
                   flag=1;
               }
               else
               {
                   cout<<" * "<<i<<" ("<<Prime_fact[i]<<")";
               }

           }
       }
       cout<<endl;
       for(i=0;i<127;i++)
        Prime_fact[i]=0;
   }
   return 0;
}

