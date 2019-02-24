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

        char str3[20000],str[20000];
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
           char str3[20000];
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


string convert_str(long long int n)
{
    //cout<<"in"<<endl;
    vector<char>vct;
    char str[10];
    int k,l;
    k=0;
    do
    {
        vct.push_back(((n%10)+48));
        n=n/10;
    }
    while(n!=0);

    reverse(vct.begin(),vct.end());

    l=vct.size();
    for(int l1=0;l1<l;l1++)
    {
        str[k++]=vct[l1];
    }
    str[k]='\0';
    vct.clear();

    return str;

}
int main()
{
    long long int num,i,l,arr[10];
    string str,st1,st[367];
    st[1]=convert_str(1);
    st[0]=convert_str(1);
        st1=convert_str(1);
        for(i=2;i<=366;i++)
        {

            str=convert_str(i);
             st1=multiply(st1,str);
             st[i]=st1;

            str.clear();


        }

        while(cin>>num && num!=0)
        {

          for(i=0;i<10;i++)
            arr[i]=0;

            l=st[num].size();
            for(i=0;i<l;i++)
            {
               arr[st[num][i]-48]++;
            }

            cout<<num<<"! --\n";
            for(i=0;i<10;i++)
            {
                if(i==5)
                    cout<<"\n";

                printf("   (%lld)%4lld",i,arr[i]);

            }

            cout<<endl;
        }

    return 0;


}






