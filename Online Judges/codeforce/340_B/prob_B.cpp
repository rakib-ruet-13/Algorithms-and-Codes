#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int arr[1000];

int main()
{
    long long n;
    arr[0]=1;

    int m=0;

    cin>>n;
    for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            if(arr[i]==1)
                m++;

        }
    arr[n+1]=1;

    long long int res=1;

    int cnt=0;
    bool flag=0;

    for(int i=1;i<=n;i++)
    {
        if(flag==0 && arr[i]==1)
            flag=1;


        else if(flag==1 && arr[i]==0)

        {
            cnt++;
        }
        else if(arr[i-1]==0 && arr[i]==1 && flag==1)
        {
            cnt+=1;
            res=res*cnt;
            cnt=0;

        }



    }
    if(m==0)
        cout<<"0"<<endl;
    else

    cout<<res<<endl;



    return 0;
}
