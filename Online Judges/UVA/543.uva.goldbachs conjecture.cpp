#include<iostream>
#define MAX 10000000
using namespace std;
void Gen_prime(void);
bool sieve[MAX];

int main()
{
    Gen_prime();
    bool check;
    long long int num,i,j;
    while(cin>>num && num!=0)
    {
        check=0;
        for(i=num-1;i>1;i-=2)
        {
            if(sieve[i]==0)
            if(sieve[num-i]==0 && (num-i)!=1)
            {
                if(i<num-i)
                        cout<<num<<" = "<<i<<" + "<<num-i<<endl;
                        else
                            cout<<num<<" = "<<num-i<<" + "<<i<<endl;
                            break;

            }
      }
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
