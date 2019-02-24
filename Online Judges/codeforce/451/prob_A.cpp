#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin>>n;

    int cnt1=0;
    int cnt2=0;

    ll n1,n2;
    n1=n2=n;

    while(n1%10!=0)
    {
        n1--;
        cnt1++;

    }

     while(n2%10!=0)
    {
        n2++;
        cnt2++;

    }

    if(cnt1<cnt2)
        cout<<n1;
    else
        cout<<n2;
    cout<<endl;





    return 0;
}
