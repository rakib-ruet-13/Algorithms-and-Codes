#include<iostream>
#include<stdio.h>
#include<ctype.h>
using namespace std;

int main()
{
    long long int arr[255];
    char str[255];
    string st;

    long long int tc,l,n,m,sum,pr,i,k;
    cin>>tc;
    while(tc--)
    {
        sum=0;
       cin>>n;
       for(i=0;i<n;i++)
       {
           cin>>str[i];
           cin>>arr[i];
       }

      cin>>m;
      getline(cin,st);
      for(i=0;i<m;i++)
      {
          getline(cin,st);
          l=st.size();
          for(int j=0;j<l;j++)
          {
              pr=0;
             for( k=0;k<n;k++)
             {
                 if(st[j]==str[k])
                 {
                     //cout<<st[i]<<"   "<<cout<<arr[k]<<endl;
                     pr=arr[k];
                     break;
                 }

             }
             sum=sum+pr;
          }
          st.clear();
      }
      printf("%.2f$\n",double(sum/100.00));

    }
}
