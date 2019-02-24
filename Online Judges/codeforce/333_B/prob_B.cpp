#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int arr[100010];


int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int k=0,k2=0;
    int m=arr[k],m2=arr[k];

    int cnt=1;
    int mx=1,z=0;

    while(k2<=n-1)
   {

        if(k==k2)
        {
            k2++;
        }
        else
        {
            if(arr[k2]<=m)
           {
            k=k2;
            m=arr[k2];

           }
           if(arr[k2]>=m2)
           {
               m2=arr[k2];
               z=arr[k2];
           }

         if(abs(m-arr[k2])<=1 && abs(m2-arr[k2])<=1)
         {
           cnt++;
           k2++;

         }
        else
        {
            if(abs(m-arr[k2])>1 || abs(m2-arr[k2])>1)
            {
                mx=max(mx,cnt);
                cnt=1;
                m=arr[k2];
                m2=arr[k2];
                k=k2;
            }
            else
            {



             mx=max(mx,cnt);
             if(z>k)
             {
                 m2=arr[++z];
                 cnt=k2-z+1;
                 k=z+1;

             }
            else
                {

                   m=arr[++k];
                   cnt=k2-k+1;
                   z=k+1;



                }

            }
        }

        }


    }
     mx=max(mx,cnt);
    cout<<mx<<endl;


}
