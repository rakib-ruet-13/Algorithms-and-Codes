#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cmath>
#define MAX 1001
using namespace std;




void Gen_prime(void);
void Gen_anaPrime();
int anaPrime(int i);
int find_digit(int num);


bool sieve[MAX];
vector<int>anaprime;
vector<int>a;

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

void Gen_anaPrime()
{

    int i,t=0;
    for(i=2;i<1000;i++)
    {
        a.clear();
        if(anaPrime(i)==1)
            {
                anaprime.push_back(i);
            }
    }
}

int anaPrime(int num)
{
    int temp,i;
    while(num)
    {
        a.push_back(num%10);
        num=num/10;
    }


    sort(a.begin(),a.end());

   do
    {
        temp=0;
        for(i=0;i<a.size();i++)
            temp=temp*10+a[i];

            if(sieve[temp]!=0)
                return 0;
    }
    while(next_permutation(a.begin(),a.end()));


        return 1;
}



int main()
{
    Gen_prime();
    Gen_anaPrime();
    long long int num,ll,up,ans,i;
    while(cin>>num && num!=0)
    {
        ans=0;
        if(num<10)
            up=10;
        else if(num<100)
            up=100;
        else if(num<1000)
            up=1000;

            for(i=0;i<anaprime.size() && anaprime[i]<up;i++)
            {
                if(num<anaprime[i])
                {
                    ans=anaprime[i];
                    break;
                }
            }
            cout<<ans<<endl;
    }
}
