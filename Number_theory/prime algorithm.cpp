#include<bits\stdc++.h>
#define MAX 20000000
using namespace std;
bool sieve[MAX];
int main()
{

    unsigned long long int num;

    static unsigned long long int i,j;

    //for(i=2;i<=MAX;i++)
       // sieve[i]=0;

    for(i=4;i<=MAX;i+=2)
        sieve[i]=1;
       // cout<<sieve[6];
    for(i=3;i*i<=MAX;i+=2)
    {
        if(sieve[i]==0)
            for(j=i*i;j<=MAX;j=2*i+j)
            sieve[j]=1;
    }
     //cout<<sieve[6];
     while(1)
    {cin>>num;
    if(sieve[num]==1)
        printf("not prime");
    else
        printf(" prime");}


}
