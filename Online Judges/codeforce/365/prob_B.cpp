#include<iostream>
#include<bits/stdc++.h>

#define pb push_back
#define uu first
#define vv second
#define inf 20000000000
#define Max 100010
#define pi acos(-1.0000)
#define REP(i,n) for(int i=1;i<=n;i++)
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define all(x) (x.begin(),x.end())


using namespace std;
typedef long long ll;
string str;
vector<ll>vct;

ll arr[100100];
ll cap[100100];
ll ans[100100];

ll power(int n,int k)
{
    if(k<=0)
        return 1;
    ll res=1;

    for(int i=1; i<=k ;i++)
    {
        res*=n;
    }
    return res;
}

int main()
{
    ll n,k;

    cin>>n>>k;

    ll temp=1;

    mem(cap,0);

    for(int i=1 ;i<=n ;i++)
    {
        cin>>arr[i];
        temp*=arr[i];
    }

    for(int j=1; j<=k; j++)
    {
        int id;
        cin>>id;
        cap[id]++;
    }


    ll res=0;

    for(int i=1;i<=n;i++)
    {
         if(i==n)
        {
            res+=arr[i]*arr[1];
        }
        res+=arr[i]*arr[i+1];

    }

    cout<<res<<endl;

    ll cnt=0;

    for(int i=1; i<=n ;i++)
    {
        if(cap[i]>0)
        {
            cnt++;

            if(i==1)
            {
                temp=temp/arr[i];

                res+= ((temp* power(arr[i],n-2-cnt) /arr[i+1]))/arr[n] ;

            }
            else if(i==n)
            {
                temp=temp/arr[i];
                res+= ((temp* power(arr[i],n-2-cnt) / arr[1]))/arr[n-1] ;


            }
            else
            {
                 temp=temp/arr[i];
                 res+= ((temp* power(arr[i],n-2-cnt) / arr[i+1]))/arr[i-1] ;

            }

        }
    }

    cout<<res<<endl;






    return 0;
}

