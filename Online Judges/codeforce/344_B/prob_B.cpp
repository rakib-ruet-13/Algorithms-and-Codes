#include<iostream>
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define pb(x) push_back(x)
#define mod (1e9+7)ll
#define pi acos(-1.0000)
#define pii pair<long long,long long>
#define VI vector<long long>
#define CLEAR(a)  memset(a,0,sizeof(a))
#define ALL(x) (x.begin(),x.end())
#define pis pair<int,string>
#define mp make_pair
#define Max 100010
#define mem(x,val) memset(x,val,sizeof(x))
#define iread(a) scanf("%d",&a)
#define llread(b) scanf("%lld",&b)
#define dread(d) scanf("%lf",&d)

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    static int a=n+1,b=m+1;

    int arr[a][b];

    for(int i=1; i<=n;i++)
        for(int j=1 ;j<=m ;j++)
    {
        arr[i][j]=0;
    }


    for(int i=1; i<=k ;i++)
    {
        int p,q,r;

        cin>>p>>q>>r;
        if(p==1)
        {
           for(int f=1;f<=m;f++)
            arr[q][f]=r;
        }

        else
        {
            for(int f=1;f<=n;f++)
            arr[f][q]=r;
        }


    }

     for(int i=1; i<=n;i++)
     {

        for(int j=1 ;j<=m ;j++)
    {
        if(j==1)
            cout<<arr[i][j];
        else
        cout<<" "<<arr[i][j];
    }

    cout<<endl;
     }






}
