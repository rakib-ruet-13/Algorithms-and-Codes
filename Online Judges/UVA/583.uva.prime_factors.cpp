#include<iostream>
#include<stdio.h>
#define MAX 10000000
using namespace std;

bool sieve[MAX];
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

int main()
{
    long long int num,temp;
    static int cnt;

    Gen_prime();

    while(scanf("%lld",&num)==1 && num!=0)
    {
        printf("%lld = ",num);
        cnt=0;
        if(num<0)
        {
            printf("-1");
            num=num*-1;
            cnt=1;
        }
        temp=num;



    while(num%2==0)
        {
            if(cnt==0)
                {
                    cout<<"2";
                    cnt=1;
                }
            else
                cout<<" x 2";

            num=num/2;

        }

    for(long int i=3;i*i<=temp; )
        {
        if(sieve[i]==0)

        if(num%i==0)
         {
             if(cnt==1)
              cout<<" x "<<i;
             else
              {
              cout<<i;
              cnt=1;
              }
          num=num/i;
         }
         else
            i=i+2;
         else
            i=i+2;
         }

    if(num!=1)
        {
            if(cnt==0)
                cout<<num;

            else
            cout<<" x "<<num;

        }

        cout<<endl;




    }
    return 0;


}

