#include<iostream>
#define MAX 100000
using namespace std;
void Gen_prime(void);
bool sieve[MAX];

int main()
{
    int cnt;
    Gen_prime();
    long long int num,i,j;
    while(cin>>num && num!=0)
    {
        cnt=0;
        for(i=num-1;i>=num/2;i-=2)
            if(sieve[i]==0)
              if(sieve[num-i]==0 && (num-i)!=1)
           cnt++;

           if(num==4)
            cout<<1<<endl;
           else
            cout<<cnt<<endl;

    }
}

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

