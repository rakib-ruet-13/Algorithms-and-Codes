#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull check_bit(ull N,int POS){return (N & (1ULL<<POS));}

ull gauss_elimination(ull arr[],int n)
{
     int len=log2(arr[0]);

     len=min(len,63);

     //cout<<len<<endl;

     int ind=0;

     for(int bit=len; bit>=0; bit--)
     {
         int x=ind;

         while(check_bit(arr[x],bit)==0 && x<n)
            x++;
         if(x==n)
            continue;
       // cout<<"x  =  "<<x<<endl;

         swap(arr[ind],arr[x]);

         //cout<<arr[ind]<<endl;

         for(int j=0; j<n ; j++)
         {
            // cout<<"arr[j] "<<arr[j]<<" "<<j<<" "<<ind<<"  "<<bit<<endl;

             //cout<<" checker = "<<arr[j]<<" nth="<<bit<<"  res= "<< check_bit(arr[j],bit)<<endl;
             if(check_bit(arr[j],bit) && j!=ind)
               {
                   //cout<<"++ "<<arr[j]<<" bit "<<bit<<endl;
                   arr[j]^=arr[ind];
               }
         }
         ind++;

     }
     ull ans=0;

     for(int i=0; i<n ; i++)
        {
           // cout<<arr[i]<<endl;
            ans=max(ans,ans^arr[i]);
        }

     return ans;


}



bool comp(ull a,ull b)
{
    return a>b;
}

int main()
{
    int tc;
    scanf("%d",&tc);
    ull arr[100010];

    for(int cs=1 ;cs<= tc ;cs++)
    {
        int n;
        scanf("%d",&n);

        for(int i=0; i<n; i++)
            scanf("%llu",&arr[i]);
        sort(arr,arr+n,comp);

        printf("Case %d: %llu\n",cs,gauss_elimination(arr,n));



    }


    return 0;
}
