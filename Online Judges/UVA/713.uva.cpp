#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctype.h>

using namespace std;
int main()
{
    string str,str1,str2,str4;
    char str3[500];

    int tc,l1,l2,k,sum,hand,i,j,p,flag;
    cin>>tc;
    getline(cin,str);
    while(tc--)
    {
        cin>>str1;
        cin>>str2;

        l1=str1.size();
        l2=str2.size();

        reverse(str1.begin(),str1.end());
        reverse(str2.begin(),str2.end());

        i=l1-1;
        j=l2-1;
        k=0;
        hand=0;
        while((i>=0 || j>=0))
        {
          if(j>=0 && i>=0 )
          {
              sum=(str1[i]-48)+str2[j]-48+hand;
              str3[k++]=(char)(sum%10+48);
              hand=sum/10;
              i--;
              j--;
          }
          else if(i>=0)
          {
              sum=(str1[i]-48)+hand;
              str3[k++]=(char)(sum%10+48);
              hand=sum/10;
              i--;
          }
          else
          {
               sum=str2[j]-48+hand;
               str3[k++]=(char)(sum%10+48);
               hand=sum/10;
               j--;

          }
        }
        k--;
        p=0;
         flag=0;
        for(int l=0;l<=k;l++)
        {

            if(str3[l]!='0')
                flag=1;

            if(flag==1)
            str4[p++]=str3[l];
        }

        for(int l=0;l<p;l++)
        {
            cout<<str4[l];
        }

        if(hand!=0)
        cout<<1;
        cout<<endl;
        str1.clear();
        str2.clear();


    }
    return 0;
}
