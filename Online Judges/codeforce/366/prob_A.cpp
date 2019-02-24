#include<iostream>
#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define uu first
#define vv second
#define mem(x,val) memset(x,val,sizeof(x))
#define REP(i,n) for(int i=1; i<=n ;i++)
#define rep(n) for(int i=0; i<n;i++)
#define pi acos(-1.0000)
#define all(x) (x.begin(),x.end())
#define Max 100100


using namespace std;

ll res;

int main()
{

    int n;
    int cnt=0;
    res=0;
    cin>>n;

    for(int i=1;i<=n ;i++)
    {
        int a;
        scanf("%d",&a);

        if(a==1)
            cout<<2<<endl;
        else
        {
            res= (res+a-1)%2;

            if(res==1)
                cout<<1<<endl;
            else
                cout<<2<<endl;


        }
    }



    return 0;
}
