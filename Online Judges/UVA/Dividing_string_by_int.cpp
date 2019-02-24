#include<iostream>
#include<bits\stdc++.h>

using namespace std;


string divide(string str,long long int div)

{
    char st[1000000];
    st[0]='\0';
    long long int flag,i,l,num,k=0;
    l=str.size();

    flag=0;
    num=str[0]-48;
    i=1;
    while(i!=l)
    {
       while(num<div && i!=l)
       {
           num=num*10+(str[i++]-48);

           if(flag!=0 && num<div)
           {
               st[k++]='0';
               cout<<0;
           }
       }
       flag=1;
       st[k++]=char(num/div+48);
       num=num%div;
       cout<<st[k-1];

    }
    st[k]='\0';
    cout<<"\n"<<num<<endl;

    return st;


}

int main()
{

    string str,ans;
    long long int divider;


    while(getline(cin,str)  && !(str.size()==1 && str[0]=='0'))
    {
      cin>>divider;
      str=divide(str,divider);
      cout<<str<<endl;
      getchar();

    }



}
