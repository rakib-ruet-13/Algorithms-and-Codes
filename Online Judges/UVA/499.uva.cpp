#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    int i,j,max;
  string str;
  int arr[26],arr2[26] ;
  //cout<<(int)'A';
  //cout<<(int)'a';

  while(getline(cin,str))
  {
      max=0;
      for(i=0;i<26;i++)
      arr[i]=0;
      for(i=0;i<26;i++)
      arr2[i]=0;

      j=str.size();
       for(i=0;i<j;i++)
       {
         if(str[i]>='A' && str[i]<='Z')
         {
             arr[(int)str[i]-65]++;
         }
         else if(str[i]>='a' && str[i]<='z')
         {
             arr2[(int)str[i]-97]++;
         }
       }

     for(i=0;i<26;i++)
        if(arr[i]>max)
        max=arr[i];

        for(i=0;i<26;i++)
        if(arr2[i]>max)
        max=arr2[i];

     for(i=0;i<26;i++)
     {
         if(arr[i]==max)
            cout<<(char)(i+65);
     }
     for(i=0;i<26;i++)
     {
         if(arr2[i]==max)
            cout<<(char)(i+97);
     }
     cout<<" "<<max<<endl;


}
}
