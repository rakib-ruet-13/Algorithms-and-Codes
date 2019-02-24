#include<iostream>
#include<bits/stdc++.h>

#define Max 110

using namespace std;

vector<int>vct;
int s;


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

    s=vct.size();
}


int prime_fact[101];

void gen_prime_factor(int n)
{
    for(int i=2;i<=n;i++)
    {
        int num=i;

        int j=0;

        while(num>1 && j<s && vct[j]<=sqrt(num))
        {
            if(sieve[num]==0)
                break;

            if(num%vct[j]==0)
            {
                int cnt=0;
                while(num%vct[j]==0)
                {
                    num=num/vct[j];
                    cnt++;
                }
                prime_fact[vct[j]]+=cnt;


            }
            else
                j++;
        }
        if(num!=1)
            prime_fact[num]+=1;

    }
}


int main()
{

    Genprime();
    int SIZE=vct.size();

    int num,n;
    int tc;
    scanf("%d",&tc);

    for(int cs=1;cs<=tc;cs++)
    {
        scanf("%d",&n);

        memset(prime_fact,0,sizeof(prime_fact));

        gen_prime_factor(n);


        printf("Case %d: %d =",cs,n);
        //printf("Case 3: 6 = 2 (4) * 3 (2) * 5 (1)")

        bool flag=0;

        for(int i=2;i<=100;i++)
        {
            if(prime_fact[i]!=0 && flag==0)
                {
                    printf(" %d (%d)",i,prime_fact[i]);
                    flag=1;
                }
                else if(prime_fact[i]!=0)
                {
                     printf(" * %d (%d)",i,prime_fact[i]);
                }

        }
        printf("\n");




    }

    return 0;
}

