#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define MAX 40000001
using namespace std;

vector<long long int>prime,dis_prime;

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
    prime.push_back(2);
    for(i=3;i<MAX;i+=2)
        if(!sieve[i])
        prime.push_back(i);
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
    long long int ll,ul,i,max,min,num1,num2;
    while(cin>>ll>>ul)
    {
        max=0;
        min=100000000000;
        if(ul<40000000)
        {
          i=0;
          while(prime[i]<ll)
                i++;

          for( ;prime[i]<=ul;i++)
            dis_prime.push_back(prime[i]);
        }
        else
        {
            if(ll%2==0)
                ll=ll+1;
            for(i=ll;i<=ul;i+=2)
            {
                if(i<40000000)
                    {if(!sieve[i])
                    dis_prime.push_back(i);}
                else
                {
                    if(Ext_sieve(i))
                        dis_prime.push_back(i);
                }

            }

        }
        if(!(dis_prime.size()<2))
        {for(i=1;i<dis_prime.size();i++)
        {
           if(dis_prime[i]-dis_prime[i-1]<min)
           {
               min=dis_prime[i]-dis_prime[i-1];
               num1=i-1;
           }
           if(dis_prime[i]-dis_prime[i-1]>max)
           {
               max=dis_prime[i]-dis_prime[i-1];
               num2=i-1;
           }
        }
        cout<<dis_prime[num1]<<","<<dis_prime[num1+1]<<" are closest, "<<dis_prime[num2]<<","<<dis_prime[num2+1]<<" are most distant."<<endl;
        }
        else
            cout<<"There are no adjacent primes."<<endl;
            dis_prime.clear();


    }
    return 0;
}


