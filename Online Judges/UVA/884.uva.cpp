#include<iostream>
#define MAX 1000002
using namespace std;
void Gen_prime(void);
int dp[1000002];
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

int Gen_prime_fact(long long int num)
{

  long long int temp,i,j,ans;

  ans=0;


  for(int k=2;k<=1000000;k++)
  {
        temp=k;

   while(temp%2==0)
        {

            ans++;
            temp=temp/2;
        }

    for(i=3;i*i<=num && sieve[temp];)
        {
        if(sieve[i]==0)

        if(temp%i==0)
         {
          ans++;
          temp=temp/i;
         }
         else
            i=i+2;
        else
            i=i+2;

         }

    if(sieve[temp]==0 && temp!=1)
        {
         ans++;
        }
        dp[k]=ans;
  }


}

int main()
{
    Gen_prime();
    long long int num;

    Gen_prime_fact(num);

    while(cin>>num)
    {
        cout<<dp[num]<<endl;
    }

    return 0;
}

