#include<iostream>
#include<bits/stdc++.h>


using namespace std;

long long tt,n;
long long t_curr[35],coin[35];
long long dp[35][1011];
vector<int>vct;
int dir[35][1011];


long long calc(int pos,int ctime)
{

    if(pos>=n+1)
    {
        return 0;
    }

    if(ctime>tt)
        return 0;

    if(dp[pos][ctime]!=-1)
        return dp[pos][ctime];


    long long int res1=0;
    long long int res2=0;


    if(t_curr[pos]+ctime<=tt)
    {
        res1=coin[pos]+calc(pos+1,ctime+t_curr[pos]);

    }

    res2=calc(pos+1,ctime);

    if(res1>res2)
    {

       dir[pos][ctime]=1;
    }
    else
    {
        dir[pos][ctime]=2;
    }

    return dp[pos][ctime]=max(res1,res2);
}




int main()
{
    int w;
    bool line=false;
    while(cin>>tt>>w)
    {
        cin>>n;
        for(int i=1;i<=n ;i++)
        {
            int a,b;
            cin>>a>>b;
            t_curr[i]=3*w*a;
            coin[i]=b;

           // cout<<"t_curr="<<t_curr[i]<<" coin="<<coin[i]<<endl;
        }


        for(int i=0;i<=n;i++)
         for(int j=0; j<=tt; j++)
            {
                dp[i][j]=-1;
                dir[i][j]=-1;
            }



        if(line)
            cout<<endl;
        line=true;

        long long res=calc(1,0);
        cout<<res<<endl;

        int k=0;



        int i,j,p;

        i=1;j=0;
        p=0;


        int cnt=0;

       bool mark[35];
       memset(mark,false,sizeof(mark));

        j=0;
        for(i=1; i<=n ;i++)
        {
            if(dir[i][j]==1)
            {
                j=j+t_curr[i];
                mark[i]=true;
                cnt++;
            }
        }

        cout<<cnt<<endl;

        for(i=1;i<=n;i++)
        {
            if(mark[i])
             cout<<t_curr[i]/(w*3)<<" "<<coin[i]<<endl;

        }


    }


    return 0;
}

