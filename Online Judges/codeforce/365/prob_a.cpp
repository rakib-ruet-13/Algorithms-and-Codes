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

int main()
{
    ll n;

    cin>>n;


    int cnt1,cnt2;

    cnt1=cnt2=0;

    for(int i=1; i<=n ;i++)
    {
        int a,b;
        cin>>a>>b;

        if(a>b)
            cnt1++;
        if(b>a)
            cnt2++;

    }

    if(cnt1>cnt2)
        cout<<"Mishka"<<endl;
    else if(cnt2>cnt1)
        cout<<"Chris"<<endl;
    else
        cout<<"Friendship is magic!^^"<<endl;







    return 0;
}

