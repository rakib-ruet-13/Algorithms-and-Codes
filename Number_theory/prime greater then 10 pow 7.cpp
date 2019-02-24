#include<bits\stdc++.h>
#define MAX 40000000
using namespace std;
void Gen_prime(void);
bool sieve[MAX];
void Gen_prime(void)
{

    unsigned long long int num;

    static unsigned long long int i,j;
    for(i=4;i<MAX;i+=2)
        sieve[i]=1;
    for(i=3;i*i<MAX;i+=2)
    {
        if(sieve[i]==0)
            for(j=i*i;j<MAX;j=2*i+j)
            sieve[j]=1;
    }
}

bool Ext_sieve(long long int num)
{
    if(num%2==0)
        return false;
    for(int i=3;i*i<=num ;i+=2)
    {
        if(sieve[i]==0)
        if(num%i==0)
            return false;
    }
    return true;
}
int main()
{
    long long int num;
    Gen_prime();
    while(cin>>num && num!=0)
    {

        {
            if(Ext_sieve(num)==0)
                cout<<"not prime"<<endl;
            else
                cout<<"prime"<<endl;
        }
    }

}

