#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int arr[100000+20];

int main()
{

    double mid;
    long long ans=0,ans2=0,dis;
    long long sum=0;
    int mid1,mid2;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum=sum+arr[i];
    }
     bool flag=false;
     if(sum%n==0)
     {

          mid1=sum/n;
          flag=true;
     }

     else
        mid1=sum/n;



    if(flag)
    for(int i=0;i<n;i++)
    {
        if(mid1>arr[i])
        {
            dis=(mid1-arr[i]);
            ans+=dis;

        }
        else
        {
            dis=(arr[i]-mid1);
            ans2+=dis;
        }
    }

    else
         for(int i=0;i<n;i++)

    {

        if(mid1>arr[i])
        {
            dis=(mid1-arr[i]);
            ans+=dis;

        }
        else if(arr[i]>mid1)
        {
            dis=(arr[i]-mid1-1);
            ans2+=dis;
        }


    }

    cout<<max(ans,ans2)<<endl;








}
