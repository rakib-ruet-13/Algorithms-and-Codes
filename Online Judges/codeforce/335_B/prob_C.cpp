#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int arr[200000];
int main()
{
    int n;
    int i;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int cnt1=1;
    int m1=0;
    int k1=0;

     for( i=0;i<n;i++)
     {
         if(arr[i]==cnt1)
            {
                cnt1++;
                m1++;
            }

     }


     m1=n-m1;



     int m2=0;
     int cnt2=n;
     for(i=n-1;i>=0;i--)
     {
         if(arr[i]==cnt2)
           {
             m2++;
             cnt2--;
           }


     }

     m2=n-m2;


     cout<<min(m1,m2)<<endl;





}
