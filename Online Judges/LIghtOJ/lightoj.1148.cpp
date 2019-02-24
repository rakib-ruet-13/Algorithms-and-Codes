#include<iostream>
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<=b ;i++)
#define pb push_back
#define read64(x) scanf("%lld",&x)
#define read32(x) scanf("%d",&x)
#define ll long long
#define pi acos(-1.000)
#define Max 1010

using namespace std;

int main()
{
    map<int,int>mymap;
    map<int ,int> :: iterator it;


    int tc;
    read32(tc);

    rep(cs,1,tc)
    {
        int n;
        read32(n);

        rep(i,1,n)
        {
            int val;
            read32(val);
            mymap[val+1]++;
        }

        long long res=0;

        for( it=mymap.begin() ; it!=mymap.end() ;it++)
        {
            int mod=it->second%it->first;
            int val=it->second;
            int index=it->first;

            res+=(val/index)*index;
            if(mod!=0)
                res+=index;
        }
        printf("Case %d: %lld\n",cs,res);
        mymap.clear();
    }
    return 0;

}
