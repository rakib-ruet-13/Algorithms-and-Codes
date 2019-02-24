#include<iostream>
#include<cstring>

using namespace std;


long long int divide(string str,long long int div)

{
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

       }
       num=num%div;

    }
    return num;


}

int main()
{

    string str;
    long long int divider,ans;
    divider=17;


    while(getline(cin,str)  && !(str.size()==1 && str[0]=='0'))
    {
      ans=divide(str,divider);
      if(ans)
        cout<<"0"<<endl;
      else
        cout<<1<<endl;


    }
    return 0;



}

