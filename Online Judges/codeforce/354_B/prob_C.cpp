#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define rep(i,p,n) for( i = p; i<n;i++)
#define lld long long int
#define fileRead(a) freopen("a","r",stdin)

#define read(a) scanf("%d",&a)
#define Lread(a) scanf("%lld",&a)
#define Uread(a) scanf("%llu",&a)
#define Dread(a) scanf("%lf",&a)
#define write(a) printf("%d\n",a)
#define Case(a) printf("Case %d: ",a)

#define pb push_back
#define VI vector<int>
#define VL vector<long long int>
#define VD vector<double>

#define PR pair<int,int>
#define MP(a,b) make_pair(a,b)

#define Clear(a,b) memset(a,b,sizeof(a))




int main()
{
    int n;
    int arr[200];

    cin>>n;
    int i,j;
    rep(i,1,n+1)
    {
        cin>>arr[i];
    }

    int posm,posM;
    int Max = -34;
    int Min = 3434;

    rep(i,1,n+1)
    {
        if(arr[i]>Max)
        {
            Max=arr[i];
            posM = i;
        }
        if(arr[i]<Min)
        {
            Min=arr[i];
            posm = i;
        }

    }

    int ret1 = max(abs(posM-1),(n-posM));
    int ret2 = max(abs(posm-1),(n-posm));

    cout<<max(ret1,ret2)<<endl;

    return 0;
}
