#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctype.h>

using namespace std;

string add_string(string str1,string str2)
{

        char str3[5000],str[5000];
        int tc,l1,l2,k,sum,hand,i,j,p,flag,m;
        free(str3);
        free(str);

        l1=str1.size();
        l2=str2.size();

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
        if(hand!=0)
            str3[k++]='1';
            k--;

        m=0;
        for(int l=k;l>=0;l--)
        {
            str[m++]=str3[l];
        }
        str[m]='\0';


        return str;

}

int main()
{
    string st[2005];
    cin>>st[1]>>st[2];
    st[3]=add_string(st[1],st[2]);
    cout<<st[3]<<endl;
    return 0;

}

