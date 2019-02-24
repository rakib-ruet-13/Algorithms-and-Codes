#include<iostream>
#include<bits/stdc++.h>
#define inf 99999999999999
#define pb push_back
#define pi acos(-1.000)
#define all(x) (x.begin(),x.end())
#define VI vector<long long>

using namespace std;

typedef long long ll;


int arr[10100];

int main()
{

    memset(arr,0,sizeof(arr));

    ll n;
    cin>>n;

    for(int i=1; i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;

        arr[a]++;
        arr[b]++;
    }


    ll res=0;
    for(int i=1;i<=n;i++)
    {
        res+=((arr[i]*(arr[i]-1))/2);
    }

    cout<<res<<endl;





    return 0;
}


