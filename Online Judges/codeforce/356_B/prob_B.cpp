#include<iostream>
#include<bits/stdc++.h>


using namespace std;

long long int arr[100100];
vector<long long>vct;

int main()
{
    string str;
    long long n;

    n=5;
    int sum=0;


    for(int i=0;i<5 ; i++)
    {
        int a;
        cin>>a;
        arr[a]++;
        sum=sum+a;

    }


   int m1=0;
   int m2=0;

   bool  flag=false;
   for(int i=0;i<=100 ;i++)
   {
       if(arr[i]>=2 && !flag)
       {
           if(arr[i]>2)
           {
              m1=i*3;
           }
           else
            m1=i*2;

            flag=true;
       }

       if(arr[i]>=2 && flag)
       {
            if(arr[i]>2)
           {
              m2=i*3;
           }
           else
            m2=i*2;

       }
   }


   m2=max(m1,m2);

   cout<<sum-m2<<endl;


    return 0;
}

