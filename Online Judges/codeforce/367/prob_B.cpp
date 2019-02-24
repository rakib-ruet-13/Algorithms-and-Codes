#include<iostream>
#include<bits/stdc++.h>
#define Max 500000

using namespace std;

typedef long long ll;

ll arr[1000100];

int main()
{

    ll n;

    cin>>n;

    memset(arr,0,sizeof(arr));

    for(int i=1 ; i<=n ; i++)
    {
        int a;
        cin>>a;

        arr[a]++;
    }

    for(int i=1 ;i<=100000; i++)
    {
        arr[i]=arr[i]+arr[i-1];
    }

    ll q;

    cin>>q;

    for(int i=1 ;i<=q ;i++)
    {
        int p;
        cin>>p;

        if(p>100000)
            cout<<n<<endl;
        else
            cout<<arr[p]<<endl;
    }





    return 0;
}
