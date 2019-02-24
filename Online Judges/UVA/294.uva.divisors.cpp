#include<iostream>
#include<stdio.h>
#define MAX 10000000
using namespace std;

bool sieve[MAX];
long long int cnt;
void Gen_prime(void);

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

int Fact(long long int num)
{
    long long int i,temp;
    temp=num;

    cnt=1;
        if(num%2==0)
        {
            cnt++;

        }

    for(i=3;i*i<=temp;)
        {
        if(sieve[i]==0)

        if(num%i==0)
         {
           cnt++;
         }
         else
         {
             i+=2;
         }
         else
         {
             i+=2;
         }

        }
    if(num!=1)
        cnt++;
            cnt++;
             return cnt;

}

int main()
{
    long long int ll,up,j,temp,tc,max;
    Gen_prime();

    cin>>tc;
    while(tc--)
    {
        max=-1;
        cin>>ll>>up;
        for(long long int i=ll;i<=up;i++)
        {
            j=Fact(i);
            if(j>max)
            {
                max=j;
                temp=i;
            }

        }
        cout<<temp<<"   "<<max<<endl;
    }

    return 0;


}

