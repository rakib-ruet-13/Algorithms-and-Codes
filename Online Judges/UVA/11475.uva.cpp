#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{

    static int i,j,l,flag,temp,mid,k;
    string str,str1,str2;
    while(cin>>str)
    {

     str1=str;
     reverse(str1.begin(),str1.end());
     if(str1==str)
        cout<<str1<<endl;
     else
     {

          l=str.size();
          mid=l/2;

          for(i=l/2;i<l;i++)
          {

              for(j=1;i+j<l;j++)
              {
                  if(str[i-j]==str[i+j])
                    flag=1;
                  else
                  {
                      flag=0;
                      break;
                  }
              }
              if(flag==1)
              {
                  break;
              }
          }
          if(i==l)
            i--;


            for(k=0;k<=i;k++)
                cout<<str[k];
            for(k=i-1;k>=0;k--)
                cout<<str[k];
            cout<<endl;
     }

    }
}
