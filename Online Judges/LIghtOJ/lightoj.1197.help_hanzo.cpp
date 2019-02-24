#include<iostream>
#include<bits/stdc++.h>
#define Max 1000100

using namespace std;

typedef long long ll;

bool sieve[Max+10];

void Gen_prime()
{
    for(int i=4; i<=Max;i+=2)
    {
        sieve[i]=1;
    }

    for(int i=3; i<=sqrt(Max);i+=2)
    {
        if(!sieve[i])
        {
            for(int j=i*i ;j<=Max ;j+=2*i)
                sieve[j]=1;

        }
    }

}

ll first_val(ll a,ll i)
{
    if(a%i==0)
        return (ll)max(a,i*i);
    else
        return (ll)max( a+(i-a%i), i*i);
}


bool seg_sieve[Max+1];



void Gen_seg_sieve(ll lo, ll ul)
{
    memset(seg_sieve,0,sizeof(seg_sieve));

  if(lo==1)
        seg_sieve[lo]=1;


  for(ll i=first_val(lo,2);i<=ul;i+=2)
  {
      seg_sieve[i-lo+1]=1;
  }


  for(ll i=3; i<=sqrt(ul);i++)
  {
      if(sieve[i]==0)
      {

          for(ll  j=first_val(lo,i);j<=ul ; j+=i)
                seg_sieve[j-lo+1]=1;
      }
  }


}




int main()
{
    Gen_prime();


    int tc;

    scanf("%d",&tc);

    for(int cs=1;cs<=tc; cs++)
    {

        ll a,b;
        scanf("%lld %lld",&a,&b);

        if(a>b)
            swap(a,b);

        Gen_seg_sieve(a,b);


        int cnt=0;

        for(ll i=a; i<=b;i++)
        {
            if(!seg_sieve[i-a+1])
               {
                    cnt++;
               }
        }

        printf("Case %d: %d\n",cs,cnt);


    }

}
