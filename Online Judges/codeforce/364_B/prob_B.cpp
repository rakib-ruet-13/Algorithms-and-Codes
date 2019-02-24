#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i,a) for(int i=1; i<=a ;i++)
#define ll long long
#define inf 1e9
#define mod 1e9+7
#define read(x) scanf("%d",&x);
#define read64(x) scanf("%lld",&x)
#define write(x) printf("%d\n",x)
#define write64(x) printf("%lld\n",x)
#define mem(x,val) memset(x,val,sizeof(x))
#define Max 50001

map<int,int>row,col;


int main()
{
    ll n,m;

    cin>>n;
    cin>>m;

    ll cnt;
    cnt=n*n;

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;

        row[x]++;


         ll p=row.size();
         ll q=col.size();

         if( row[x]==1)
         {
             cnt=cnt-n+q;
         }


         col[y]++;
         if(col[y]==1)
         {
             cnt=cnt-n+p;
         }

         if(i==0)
            cout<<cnt;
         else
            cout<<" "<<cnt;
    }



     cout<<endl;








    return 0;
}
