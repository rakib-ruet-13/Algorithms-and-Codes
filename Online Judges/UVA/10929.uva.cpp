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

    return temp;

}
int main()
{
    int num=11;
    while(getline(cin,str))
    {
        if(str[0]=='0' && str.size()==1)
            return 0;
        cout<<str;

        if(Find_mod(num))
        cout<<" is not a multiple of 11."<<endl;
    else
        cout<<" is a multiple of 11."<<endl;

    }


}

