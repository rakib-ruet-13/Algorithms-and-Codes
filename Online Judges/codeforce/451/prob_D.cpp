#include<iostream>
#include<bits/stdc++.h>

using namespace std;


long long arr[4001000];

int main()
{
    long long n,m,k;
    cin>>n>>m>>k;


    memset(arr,0,sizeof(arr));
    for(int i=0; i<n; i++)
    {
        long long int temp;
        cin>>temp;
        arr[temp]=1;
    }

    for(int i=1; i<=4000000; i++)
    {
        arr[i]=arr[i-1]+arr[i];

    }

    long long res=0;
    long long cnt=0;



    for(int j=m; j<=4000000; j++)
    {
        long long temp=arr[j]-arr[j-m]-cnt;
        if(temp>=k)
            {
                 if(arr[j-m]!=arr[j-m+1])
                    {
                        cnt++;
                        res++;
                    }
            }
            else
            {
                if(arr[j-m]!=arr[j-m+1] && cnt>0)
                    cnt--;
            }




    }

    cout<<res<<endl;



    return 0;
}
