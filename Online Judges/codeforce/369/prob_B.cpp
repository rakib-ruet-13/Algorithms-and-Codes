#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll grid[505][505];

int main()
{

    //freopen("input.txt","r",stdin);

    int n;
    cin>>n;

    ll row;
    ll col;

    ll res=0;
    ll sum;

    for(int i=1;i<=n ;i++)
    {

         sum=0;

        for(int j=1; j<=n ;j++)
       {
        cin>>grid[i][j];

        if(grid[i][j]==0)
        {
            row=i;
            col=j;
        }
        sum+=grid[i][j];

      }

      res=max(res,sum);

    }

    //cout<<"ok"<<endl;

    ll res1=0;

    for(int j=1; j<=n ;j++)
    {
        res1+=grid[row][j];
    }



    grid[row][col]=res-res1;



    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }

    //cout<<"ok"<<endl;




    grid[row][col]=res-res1;


     for(int i=1; i<=n ;i++)
    {

        sum=0;

        for(int j=1; j<=n;j++)
     {
        sum+=grid[j][i];
     }

      if(sum!=res)
     {
        cout<<-1<<endl;
        return 0;
     }


    }



      for(int i=1; i<=n ;i++)
    {

        sum=0;

        for(int j=1; j<=n;j++)
       {
        sum+=grid[j][i];
        }

        if(sum!=res)
        {
            cout<<-1<<endl;
            return 0;
        }

    }




    sum=0;

    for(int i=n,j=1 ; i>=1 && j<=n ; i--,j++)
    {
        sum+=grid[i][j];
    }

    if(sum!=res)
        {
            cout<<-1<<endl;
            return 0;
        }




     sum=0;
    for(int i=1 ;i<=n;i++)
    {
      sum+=grid[i][i];
    }

    if(sum!=res)
    {
    cout<<-1<<endl;
    return 0;
    }

    if(grid[row][col]>0)
    {
        cout<<grid[row][col]<<endl;
    }
    else
        cout<<-1<<endl;


    return 0;
}

