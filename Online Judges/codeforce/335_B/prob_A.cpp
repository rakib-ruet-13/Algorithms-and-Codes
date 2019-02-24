#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{

    typedef long long ll;



    ll q,n;
    ll arr[1001];
      memset(arr,0,sizeof(arr));

    cin>>q>>n;

    for(int i=0;i<q;i++)
    {
        ll p,q;
        cin>>p>>q;

        arr[p]=max(arr[p],q);
    }

    ll sum=0;
    for(int i=n;i>=0;i--)
    {
        if(sum<arr[i])
            sum+=(arr[i]-sum);
        sum++;
    }

    cout<<--sum<<endl;


}
