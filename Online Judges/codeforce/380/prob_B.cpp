#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int check(int N,int pos){ return N&(1<<pos);}
int Set(int N,int pos){ return N=(N|(1<<pos));}
int Reset(int N,int pos){ return N=(N & ~(1<<pos));}


int arr[101001];
vector<int>vct;


int main()
{

   int n;
   int x;

   cin>>n>>x;

   memset(arr,0,sizeof(arr));

   for(int i=0; i<n ;i++)
   {

       int val;
       scanf("%d",&val);

       arr[val]++;
       vct.push_back(val);
   }


    int cnt=0;

    for(int i=0; i<vct.size() ;i++)
    {


      int p=x^vct[i];


    //cout<<p<<endl;
      if(p<=100000)
     {


         if(arr[p]>=1)
             {
                 arr[vct[i]]--;
                 cnt+=arr[p];
             }
     }
    }


    cout<<cnt<<endl;



    return 0;
}


