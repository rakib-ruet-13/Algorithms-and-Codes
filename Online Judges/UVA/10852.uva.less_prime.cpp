#include<iostream>
#include<stdio.h>
#define MAX 100000
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
int main()
{
    long long tc,num,i,j,k;
    Gen_prime();
    cin>>tc;
    while(tc--)
    {
        cin>>num;
        k=0;


           for(i=1;i<=100000;i+=2)
           {
                if(sieve[i]==0)
               {
                   if(i<=num && i*2>num)
                   {
                     k=i;
                     break;

                   }
               }
           }

        cout<<k<<endl;

    }

}

