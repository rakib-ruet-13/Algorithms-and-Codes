#include<iostream>
#include<bits/stdc++.h>

#define Max 1000010

using namespace std;

vector<int>vct;


bool sieve[Max+1];

void Genprime()
{
    for(int i=4;i<=Max;i+=2)
        sieve[i]=1;
    for(int i=3;i<=sqrt(Max);i++)
    {
        if(!sieve[i])
        {
            for(int j=i*i;j<=Max;j+=2*i)
                sieve[j]=1;
        }
    }
    vct.push_back(2);

    for(int i=3;i<=Max;i+=2)
    {
        if(!sieve[i])
            vct.push_back(i);
    }
}



int main()
{

    Genprime();
    int SIZE=vct.size();

    long long num;
    int tc;
    scanf("%d",&tc);

    for(int cs=1;cs<=tc;cs++)
    {
        scanf("%lld",&num);

        long long res=1;

        int i=0;


        while(num>1 && i<SIZE && vct[i]<=sqrt(num))
        {
            if(num<=Max)
                if(sieve[num]==0)
                break;

            if(num%vct[i]==0)
            {
              int cnt=0;
              while(num%vct[i]==0)
               {
                   num=num/vct[i];
                   cnt++;
               }
               res*=(cnt+1);
            }

            i++;

        }

        if(num!=1)
            res=res*2;


        printf("Case %d: %lld\n",cs,res-1);
    }

    return 0;
}
