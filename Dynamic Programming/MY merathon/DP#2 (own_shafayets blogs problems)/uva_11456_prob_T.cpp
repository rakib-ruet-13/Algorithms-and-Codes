#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int n;
long long int arr[2111];
long long int dp1[2111];
long long int dp2[2111];

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>n;

        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }



        for(int i=n ;i>=1 ; i--)
        {
            dp1[i]=1;

            for(int j=i+1; j<=n ;j++)
            {
                if(arr[i]<arr[j])
                {
                    dp1[i]=max(dp1[j]+1, dp1[i]);
                }
            }
        }


        for(int i=n ;i>=1 ;i--)
        {
            dp2[i]=1;

            for(int j=i+1; j<=n ;j++)
            {
                if(arr[i]>arr[j])
                {
                    dp2[i]=max(dp2[j]+1,dp2[i]);
                }
            }
        }


        long long mx=0;

        for(int i=1;i<=n;i++)
        {
            mx=max(mx, dp1[i]+dp2[i]-1);
        }

        cout<<mx<<endl;

    }
}
