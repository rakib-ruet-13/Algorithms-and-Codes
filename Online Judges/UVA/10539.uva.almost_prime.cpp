#include<iostream>
#include<stdio.h>
#define MAX 1000000
using namespace std;
void Gen_prime(void);
bool sieve[MAX];
void Gen_prime(void)
{

    unsigned long long int num;

    static unsigned long long int i,j;
    sieve[0]=1;
    sieve[1]=1;
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
    Gen_prime();
    long long int ll,ul,i,cnt,tc,j;
    scanf("%lld",&tc);
    while(tc--)
    {
        cnt=0;
        cin>>ll>>ul;

          j=2;
            while(j*2<=ul )
        {
            if(j*2>=ll)
            cnt++;
            j=j*2;
        }



        for(i=3;i*i<=ul ;i+=2)
        {
            j=i;
            if(sieve[i]==0)
                while(j*i<=ul)
                {
                    if(j*i>=ll)
                    {
                     cnt++;
                    }


                    j=j*i;
                }
        }

        printf("%lld\n",cnt);
    }

}





