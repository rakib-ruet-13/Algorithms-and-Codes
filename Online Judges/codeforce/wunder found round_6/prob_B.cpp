#include<iostream>
#include<bits/stdc++.h>


using namespace std;


int main()
{

    int arr[100][100];
    int ans[1000];

    int ind[100];
    memset(ans,0,sizeof(ans));

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        cin>>arr[i][j];
    }

     for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            ans[i]=max(ans[i],arr[j][i]);
        }


    int mx=0;

    for(int i=1;i<=n;i++)
    {
        ind[ans[i]]++;
        mx=max(ans[i],mx);

    }

    for(int i=n;i>0;i--)
    {
        if(ind[i]==0)
        {
            ind[i]++;

            for(int k=1;k<=n;k++)
            {
                if(ans[k]<i && ind[ans[k]]>1)
                {
                   ind[ans[k]]--;
                   ans[k]=i;
                   break;

                }

            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(i==n)
            cout<<ans[i]<<endl;
        else
            cout<<ans[i]<<" ";
    }




}
