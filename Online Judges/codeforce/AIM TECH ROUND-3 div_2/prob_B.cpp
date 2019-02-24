#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll arr[310000];

int main()
{


    ll n,st;
    cin>>n>>st;




    for(int i=0 ;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);


    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }

    ll res=0;

    n--;

    if(arr[0]<= st && arr[n-1] >=st)
    {
        if(abs(arr[0]-st) <= abs(arr[n-1]-st))
        {
            res= 2* abs(arr[0]-st)+ abs(arr[n-1]-st);
        }
        else
        {
            res=  abs(arr[0]-st)+ 2*abs(arr[n-1]-st);
        }
    }
    else if(arr[0]>=st)
    {
        res=abs(arr[n-1]-st);
    }
    else
    {
        res=abs(arr[0]-st);
    }







      n++;

      ll res2=0;

    if(arr[1]<= st && arr[n-1] >=st)
    {
        if(abs(arr[1]-st) <= abs(arr[n-1]-st))
        {
            res2= 2* abs(arr[1]-st)+ abs(arr[n-1]-st);
        }
        else
        {
            res2=  abs(arr[1]-st)+ 2*abs(arr[n-1]-st);
        }
    }
    else if(arr[1]>=st)
    {
        res2=abs(arr[n-1]-st);
    }
    else
    {
        res2=abs(arr[1]-st);
    }

    cout<<min(res,res2)<<endl;





    //cout<<res<<endl;





    return 0;
}

