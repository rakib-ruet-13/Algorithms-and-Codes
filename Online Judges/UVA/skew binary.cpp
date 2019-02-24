#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    unsigned long long int num;
    int i,a,n;
    string str;
    while(cin>>str )
    {
        if(str.size()==1 && str[0]=='0')
            break;
       n=str.size();
       num=0;
       for(i=0;i<str.size();i++)
       {
           a=str[i]-48;
           num=num+a*(pow(2,n)-1);
           n--;
       }
       cout<<num<<endl;

    }
    return 0;

}

