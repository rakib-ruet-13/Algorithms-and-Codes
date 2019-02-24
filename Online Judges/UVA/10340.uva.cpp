#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;

string str1,str2;

using namespace std;
int main()
{
    int l1,l2,c,k,cnt;
    while(cin>>str1>>str2 )
    {
       l1=str1.size();
       l2=str2.size();
       k=0;
       cnt=0;
       {
           for(int i=0;i<l2;i++)
           {
               if(str2[i]==str1[k])
               {
                   cnt++;
                   k++;
               }

               if(cnt==l1)
                break;
           }
       }
       if(cnt==l1)
        cout<<"Yes"<<endl;
       else
        cout<<"No"<<endl;

       str1.clear();
       str2.clear();
    }
    return 0;


}

