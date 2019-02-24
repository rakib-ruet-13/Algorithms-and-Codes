#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctype.h>
#include<vector>
#include<bits/stdc++.h>

using namespace std;



string add_string(string str1,string str2)
{

        char str3[1000],str[1000];

        //free(str3);
       // free(str);
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
        str[m]='\0';


        return str;


}


string multiply(string str1,string str2)
{
    string st,ans;


    ans.clear();


    vector<char>str;
    int l,l1,l2,i,j,k;

    l1=str1.size();
    l2=str2.size();

    int cs=0;
    for( j=l2-1;j>=0;j--)

    {
           char str3[1000];
           int hand=0;
           //free(str3);


        for(i=l1-1;i>=0;i--)
        {
            int sum=(str1[i]-48)*(str2[j]-48)+hand;
            str.push_back(char(sum%10+48));
            hand=sum/10;
        }

        if(hand!=0)
             str.push_back(char(hand+48));

        reverse(str.begin(),str.end());

        for( l=0;l<cs;l++)
        {
            str.push_back('0');
        }
        k=str.size();
        for( l=0;l<k;l++)
        {
            str3[l]=str[l];
        }
        str3[l]='\0';


        ans=add_string(ans,str3);

        str.clear();
        cs++;

    }

    return ans;

}


int main()
{
    long long int num;
    string st1,st2,ans;

    while(cin>>st1>>st2)
    {



      if((st1.size()==1 && st1[0]=='0')  || (st2.size()==1 && st2[0]=='0' ))
        cout<<"0"<<endl;
      else
      {

      ans=multiply(st1,st2);
      cout<<ans<<endl;
      ans.clear();

      }



      st1.clear();
      st2.clear();

    }


    return 0;

}



