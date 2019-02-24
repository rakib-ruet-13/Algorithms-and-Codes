#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define pi acos(-1.0000)
#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)
#define ll long long
#define pb(x) push_back(x)
#define rep(i,x) for(int k=i;k<=x;k++)
#define uu  first
#define vv second
#define vaild(x,y) (x>=1 && x<=row && y>=1 && y<=row)



int main()
{

    int tc;
    int n,m,arr[10000];

    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);

    ll sum=0;
    ll cnt=0;
    for(int i=n-1;i>=0;i--)
    {
        if(sum>=m)
            break;
        else
        {
            sum=sum+arr[i];
            cnt++;
        }
    }

    cout<<cnt<<endl;



    return 0;
}

