#include<iostream>
#include<stdio.h>
#include<algorithm>
#define MAX 10000000
using namespace std;
void Gen_prime(void);
bool sieve[MAX];
bool arr[10009];
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

int Ext_sieve(long long int num)
{
    if(num%2==0)
        return 0;
    for(int i=3;i*i<num ;i+=2)
    {
        if(sieve[i]==0)
        if(num%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    Gen_prime();
    long long int ll,up,n,i;
    double ans;
    int cnt,cntp;
     //for(i=0;i<=10009;i++)

    for(i=0;i<=10009;i++)
        {
            n=i*i+i+41;
            if(n<10000000)
            {
                if(sieve[n]==0)
                  arr[i]=1;
            }
            else
            {    if(Ext_sieve(n)==1)
                arr[i]=1;
            }

        }
    while(scanf("%lld %lld",&ll,&up)!=EOF)
    {
        cnt=0;
        cntp=0;

        for(i=ll;i<=up;i++)
        {
           if(arr[i]==1)
            cntp++;

        }

        printf("%.2f\n",(double)cntp*(double)100/(double)(up-ll+1)+ 1e-9);

    }

}




