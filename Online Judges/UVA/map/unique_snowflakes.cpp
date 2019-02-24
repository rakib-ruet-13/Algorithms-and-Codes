#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int arr[10000000];

int main()
{
    long long  int n,i,m,k,var,max,tc;

    map<long long int,long long int >mymap;
    map<long long int,long long int >::iterator it;

    cin>>tc;
    while(tc--)

    {
        cin>>n;
        m=0;k=0;
        max=-9999;

        for(i=0;i<n;i++)
        {
            cin>>arr[i];
             mymap[arr[i]]++;

             if(mymap[arr[i]]>1)
             {

                 while(1)
                 {
                     if(arr[i]==arr[m])
                     {
                       m++;
                       break;
                     }
                     else
                     {
                         mymap[arr[m]]=0;
                         m++;
                     }




                 }

                 mymap[arr[i]]=1;
             }

            k++;
            //cout<<m<<"  "<<k<<endl;

            if(k-m>max)
                max=k-m;

        }
        cout<<max<<endl;
        mymap.clear();

    }

}

