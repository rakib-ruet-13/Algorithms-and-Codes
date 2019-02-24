#include<iostream>
#include<ctype.h>
#include<vector>
#include<cstring>
using namespace std;

int main()
{
   vector<char>str;
   char mid;
   int n;
   while(cin>>n)
   {
       for(int i=0;i<n;i++)
       {
           cin>>mid;
           if(i!=0)
           {
               if((str.back()=='0' && mid=='1') || (str.back()=='1' && mid=='0'))
                str.pop_back();
               else
                str.push_back(mid);
           }
           else
            str.push_back(mid);

       }
       cout<<str.size()<<endl;
       str.clear();


   }

}
