#include<bits\stdc++.h>
#define MAX 10000000
using namespace std;
void Gen_prime(void);
bool sieve[MAX];
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

long long int Gen_prime_fact(long long int num)
{


  long long int temp,i,j,flag,cnt;
  cnt=0;
  temp=num;


   while(temp%2==0)
        {
            cnt++;
            temp=temp/2;
        }



    for(i=3;i*i<=num ; )
        {
        if(sieve[i]==0)

        if(temp%i==0)
         {
          cnt++;
          temp=temp/i;
         }
         else
           {
               i=i+2;
           }
        else
           {
              i=i+2;
           }

         }

    if(temp!=1)
        {
          cnt++;
          if(temp!=num)
            cnt++;
        }

   return cnt;
}

int main()
{
    long long int num,ll,ul,mx,ans,flag;

    Gen_prime();


    while(cin>>ll>>ul)
    {
        flag=0;
        if(ll>ul)
        {
            swap(ll,ul);
            flag=1;
        }
        mx=-111111;

        for(int i=ll;i<=ul;i++)
        {
          num=Gen_prime_fact(i);
          if(num>mx)
          {
              mx=num;
              ans=i;

          }
        }
        if(ll==1)
            mx++;
        if(flag==0)
           printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",ll,ul,ans,mx);
        else
             printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",ul,ll,ans,mx);
    }
}

