#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string str1;
string str2;
int main()
{

   getline(cin,str1);
   getline(cin,str2);

   int l1=str1.size();
   int l2=str2.size();

   if(l2>l1)
   {
       reverse(str1.begin(),str1.end());
       for(int i=0;i<l2-l1;i++)
       {
           str1.push_back('0');
       }

       reverse(str1.begin(),str1.end());
   }
   else
   {
        reverse(str2.begin(),str2.end());
       for(int i=0;i<l1-l2;i++)
       {
           str2.push_back('0');
       }
        reverse(str2.begin(),str2.end());
   }

   if(str1==str2)
    cout<<"="<<endl;
   else
   {
       for(int i=0;i<str1.size();i++)
       {
           if(str1[i]!=str2[i])
           {
               if(str1[i]>str2[i])
                cout<<">"<<endl;
               else
                cout<<"<"<<endl;

               return 0;
           }
       }

   }

}
