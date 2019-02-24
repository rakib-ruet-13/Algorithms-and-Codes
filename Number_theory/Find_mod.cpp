#include<iostream>
#include<cstring>
using namespace std;

string str;

int Find_mod(int num)
{
    int l,temp=0;
    l=str.size();
    for(int i=0;i<l;i++)
    {
      temp=temp*10+str[i]-48;
      if(temp/num!=0)
            temp=temp%num;
    }
    cout<<temp;
    return temp;

}
int main()
{
    int num;
    getline(cin,str);
    Find_mod(num);

}
