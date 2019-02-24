#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool check(int n,int pos) { return n & (1<<pos); }
int Set(int n,int pos){ return n= (n | 1<<pos); }
int Reset(int n,int pos) { return n=(n & ~(1<<pos)); }

int dp[1<<13];
int N;

int solve(int mask)
{

    //cout<<mask<<endl;

    //cout<<mask<<endl;

    if(dp[mask]!=-1)
        return dp[mask];

    int res1;
    int res2;
    int mx=0;



    for(int i=0 ;i<N ;i++)
    {

        res1=res2=0;

        if(check(mask,i))
        {
            if(i+1<N && i-1>=0)
             {

                 if(check(mask,i+1) && !check(mask,i-1))
                 {


                     int p=mask;
                     p= Set(p,i-1);
                     p= Reset(p,i);
                     p= Reset(p,i+1);

                     // cout<<"p="<< p<<" "<<i<<endl;

                     res1=1+solve(p);
                    // cout<<res1<<endl;
                 }

                 if(!check(mask,i+1) && check(mask,i-1))
                 {
                     int p=mask;
                     p= Set(p,i+1);
                     p= Reset(p,i);
                     p= Reset(p,i-1);

                     res2=1+solve(p);
                 }


             }
             mx=max(mx,res1);
             mx=max(mx,res2);


        }
    }



    //cout<<mask<<endl;
    return dp[mask]=mx;
}



int main()
{
    int n;
    cin>>n;

    string str;

    for(int i=0;i<n ;i++)
    {
        cin>>str;
        N=str.size();

        //reverse(str.begin(),str.end());
        //cout<<str<<endl;
        int cnt=0;
        int mask=0;
        for(int i=0;i<str.size(); i++)
        {
            if(str[i]=='o')
            {
                cnt++;
                mask=Set(mask,i);
            }
        }
        memset(dp,-1,sizeof(dp));

        //cout<<mask<<endl;

        int res=solve(mask);
        cout<<cnt-res<<endl;

    }
}
