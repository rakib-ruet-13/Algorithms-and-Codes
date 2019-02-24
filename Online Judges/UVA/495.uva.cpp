
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

        str1.clear();
        str2.clear();

        return str;

}

int main()
{
    string st[5005];
    int n;
    st[0]="0";
    st[1]="1";
    for(int i=2;i<=5000;i++)
    {
        st[i]=add_string(st[i-1],st[i-2]);
    }
    while(cin>>n)
        cout<<"The Fibonacci number for "<<n<<" is "<<st[n]<<endl;


    return 0;

}

