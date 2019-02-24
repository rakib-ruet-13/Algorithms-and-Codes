#include<iostream>
#include<string>
using namespace std;
int main()
{
 string str;
 int i,sum;


  while(getline(cin,str))
 {

     sum=0;
     for(i=0;i<str.size();i++)
        sum+=str[i]-48;
        cout<<str;
        if(sum%2==0)
            cout<<" A"<<endl;
        else
            cout<<" B"<<endl;



 }
 return 0;

}
