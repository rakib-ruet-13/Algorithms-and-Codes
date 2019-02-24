#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string rev_sum(string str1,int base)
{
    string ans,str2;
    int carry,val1,val2,sum;
    char ch;

    str2=str1;
    carry=0;

    reverse(str2.begin(),str2.end());

    int l=str1.size();

    for(int i=l-1;i>=0;i--)
    {

        if(str1[i]>'9')
            val1=str1[i]-55;
        else
            val1=str1[i]-48;

        if(str2[i]>'9')
            val2=str2[i]-55;
        else
            val2=str2[i]-48;

        sum=val1+val2+carry;
        carry=sum/base;
        sum=sum%base;

        if(sum>9)
        {
            ch=char(sum+55);
        }
        else
            ch=char(sum+48);

        ans.push_back(ch);



    }

    if(carry!=0)
       {
           ch=char(carry+48);
           ans.push_back(ch);


       }

    reverse(ans.begin(),ans.end());

    return ans;


}

bool check(string str1)
{
    string str2;
    str2=str1;
    reverse(str2.begin(),str2.end());

    if(str1==str2)
        return true;
    else
        return false;
}

int main()
{

    string str;
    int base,flag;

    while(cin>>str>>base)
    {
        flag=0;
        for(int i=0;i<10;i++)
        {
            str=rev_sum(str,base);

            if(check(str))
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
            cout<<"NONE"<<" ";
        cout<<str<<endl;


    }
}
