#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;
#define Max 5000001

vector<int>vct;

bool sieve[Max+1];

unsigned long long  dp[Max];


inline int power(int base,int p)
{
    if(p==0)
        return 1;
    int ans=1;

    for(int i=1;i<=p;i++)
        ans=ans*base;

    return ans;
}

void Genprime()
{
    int i,j;
    for(i=4;i<=Max;i+=2)
     sieve[i]=1;

     int s=sqrt(Max);

     for(int i=3;i<=s;i+=2)
     {
         if(sieve[i]==0)
         {
             for(j=i*i;j<=Max;j+=2*i)
                sieve[j]=1;
         }
     }

     for(int i=2;i<=Max;i++)
     {
         if(!sieve[i])
            vct.push_back(i);
     }


}

inline int r_prime(int x)
{

    int i;
    if(sieve[x]==0)
        return x-1;


    int ans=1;
    i=0;

    while(x>1)
    {

        if(sieve[x]==0)
            return ans*(x-1);


        else if(x%vct[i]==0)
        {
            int cnt=0;

              while(x%vct[i]==0)
             {
                 x=x/vct[i];
                 cnt++;
             }

             if(cnt==1)
             ans=ans*(vct[i]-1);
             else
             ans*=power(vct[i],cnt)-power(vct[i],cnt-1);
        }
        else
            i++;


    }

    return ans;
}


int main()
{



    int tc,cs;
    int ll,ul;
    long long n;

     Genprime();
     dp[0]=0;
     dp[1]=0;
     int i;
     for( i=2;i<=Max;i++)
     {
        n=r_prime(i);
        dp[i]=dp[i-1]+n*n;
     }

     scanf("%d",&tc);



    for( cs=1;cs<=tc;cs++)
    {
        scanf("%d %d",&ll,&ul);
        printf("Case %d: %llu\n",cs,dp[ul]-dp[ll-1]);

    }





    return 0;
}
