#include<iostream>
#define MAX 20000000
using namespace std;
void Gen_prime(void);
void Gen_twin_prime(void);
bool sieve[MAX];
long long int arr[1000000],cnt=0;

int main()
{
    Gen_prime();
    Gen_twin_prime();

    long long int n;
    while(cin>>n)
    {
        cout<<"("<<arr[n]<<","<<" "<<arr[n]+2<<")"<<endl;
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
void Gen_twin_prime(void)
{

    long long int i;
            for(i=3;i<MAX;i+=2)
            {
                if(!sieve[i])
                {
                    if(!sieve[i+2])
                        arr[++cnt]=i;
                }
            }

}


