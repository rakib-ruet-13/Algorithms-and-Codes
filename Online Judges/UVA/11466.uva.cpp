#include<iostream>
#include<algorithm>
#define MAX 40000000
using namespace std;
void Gen_prime(void);
bool sieve[MAX];
//long long int Prime_fact[20000000];
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

  long long int temp,i,j,mx,cnt;
  cnt=-1;
  temp=num;
  mx=-1;
  // cout<<"pass test 1"<<endl;
   while(temp%2==0)
        {

            if(num!=2)
            {
                mx=2;
                cnt=2;
            }
            temp=temp/2;

        }

    for(i=3;i*i<=num ; )

        {
        if(sieve[i]==0)

        if(temp%i==0)
         {
          if(i>mx)
          {
              if(mx==-1)
              {
                  cnt=mx=i;

              }
              else
            {
                cnt=mx;
                mx=i;
            }

          }

          temp=temp/i;
         }
         else
            i=i+2;
        else
            i=i+2;

         }

    if( temp!=1)
        {
          if(temp==num)
            {
                mx=-1;
            }
          else
          {
             cnt=mx;
             mx=temp;
          }

        }
       // cout<<"pass test last "<<endl;
       if(mx==cnt)
        mx=-1;

        return mx;


}

int main()
{
    long long int num;

    Gen_prime();
    while(cin>>num && num!=0)
    {
        if(num<0)
            num=-1*num;
        cout<<Gen_prime_fact(num)<<endl;
    }
  return 0;
}

