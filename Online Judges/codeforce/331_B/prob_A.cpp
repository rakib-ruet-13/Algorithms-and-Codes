#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
{

    long long int n,arr[5][3];

    cin>>n;
    int flag=1;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i][1]>>arr[i][2];

    }


    if(n==1)
        {
            cout<<-1<<endl;
            flag=0;
        }
    else if(n==2)

         {
             if(!((arr[1][1]==arr[2][1]) || (arr[1][2]==arr[2][2] )))
            cout<<abs(arr[1][1]-arr[2][1])*abs(arr[1][2]-arr[2][2])<<endl;
             else
                {
                    cout<<-1<<endl;
                }
            flag=0;


         }

    else if(n==3)
    {

        for(int i=1;i<=n-1;i++)
        {

            for(int j=i+1;j<=n;j++)
            {
                 if(!((arr[i][1]==arr[j][1]) || (arr[i][2]==arr[j][2] )))
                 {
                    cout<<abs(arr[i][1]-arr[j][1])*abs(arr[i][2]-arr[j][2])<<endl;
                    flag=0;

                 }
            }
        }
    }

    else
    {
        int cnt=0;
        long long int mx1,mx2;
         for(int i=1;i<=n-1;i++)
        {

            for(int j=i+1;j<=n;j++)
            {
                 if(!((arr[i][1]==arr[j][1]) || (arr[i][2]==arr[j][2] )))
                 {
                     if(cnt==0)
                     {
                           mx1=abs(arr[i][1]-arr[j][1])*abs(arr[i][2]-arr[j][2]);

                     }
                     if(cnt==1)
                          mx2=abs(arr[i][1]-arr[j][1])*abs(arr[i][2]-arr[j][2]);

                      cnt++;


                 }
            }
        }

        if(cnt==2 && mx1==mx2)
        {
            cout<<mx1<<endl;

        }
        else
            cout<<-1<<endl;
    }





    return 0;
}
