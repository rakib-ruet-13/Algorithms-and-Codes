#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    string str1,str2;
    int n,t,cnt=0;

    cin>>n>>t;
    getchar();
    cin>>str1;
    cin>>str2;


    int count=0;

    bool arr[1000010];

     for(int i=0;i<n;i++)
     {
         arr[i]=0;
     }

    for(int i=0;i<n;i++)
    {
        if(str1[i]==str2[i])
            {
                arr[i]=1;
                cnt++;
            }

    }

    //cout<<cnt<<endl;

    int flag=1;

    if( n-t>cnt)
    {
        cout<<-1<<endl;
    }
    else
    {

    for(int i=0;i<n;i++)
    {
        char ch='a';
            if(arr[i]==1 && flag==1 && count<n-t)
             {
                 cout<<str1[i];
                 count++;
                 if(count==n-t)
                 {
                     flag=0;
                 }

             }
             else
             {
                 bool fg=0;
                 do

                 {
                     if(ch!=str1[i] && ch!=str2[i] )
                     {
                         cout<<ch;
                         fg=1;
                     }
                     ch++;
                 }
                 while(fg==0);

             }



    }
    cout<<endl;
    }



}
