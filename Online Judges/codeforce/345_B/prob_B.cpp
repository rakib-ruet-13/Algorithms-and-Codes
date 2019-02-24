#include<iostream>
#include<bits/stdc++.h>

using namespace std;


struct node
{
   int ind;

};

int main()
{
    long long n;


    cin>>n;

    int arr[1010];

    memset(arr,0,sizeof(arr));

    for(int i=1 ; i<= n ;i++)
    {
        int a;

        cin>>a;
        arr[a]++;

    }


    int res=0;

    int cnt=0;
    do
    {
      cnt=0;

      for(int i=1 ;i<=1000 ;i++)
      {
       if(arr[i]>0)
       {
           arr[i]--;
           cnt++;
       }
      }
      if(cnt>=1)
      res+=(cnt-1);
    }
    while(cnt>1);

    cout<<res<<endl;


    return 0;


}

