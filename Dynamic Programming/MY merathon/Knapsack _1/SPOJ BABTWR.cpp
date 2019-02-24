#include<iostream>
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<=b ;i++)
#define pb push_back
#define read64(x) scanf("%lld",&x)
#define read32(x) scanf("%d",&x)
#define ll long long
#define mod 1e9+7
#define pi acos(-1.000)
#define Max 1010

using namespace std;


int dp[1000][1000];
int n;

struct node
{
    int len;
    int wid;
    int h;
};

node arr[4000];

int cal(int i,int l)
{

    cout<<"in"<<endl;
    if(i>n)
        return 0;

    if(dp[i][l]!=-1)
        return dp[i][l];

        int res1,res2;

        res1=res2=0;

    if(arr[i].len<arr[l].len && arr[i].wid<arr[l].wid)
    {
        rep(k,1,n)
        {
            if(arr[i].len<arr[l].len && arr[i].wid<arr[l].wid)
                res1=arr[i].h+cal(k,i);
        }
    }

    res2=(i+1,l);

    return dp[i][l]=max(res1,res2);

}


int main()
{

    while(scanf("%d",&n))
    {
        if(n==0)
            break;


        int j=1;

        rep(i,1,n)
        {
            int a,b,c;

            scanf("%d %d %d",&a,&b,&c);
            arr[j].len=max(a,b);
            arr[j].wid=min(a,b);
            arr[j++].h=c;

            arr[j].len=max(b,c);
            arr[j].wid=min(b,c);
            arr[j++].h=a;

            arr[j].len=max(a,c);
            arr[j].wid=min(a,c);
            arr[j++].h=b;


        }
        arr[0].len=arr[0].wid=arr[0].h=111111111;
        n=n*3;
        rep(i,0,n+1)
        rep(j,0,n+2)
          dp[i][j]=-1;

        long long res=cal(1,0);

        printf("%lld\n",res);
    }


  return 0;
}
