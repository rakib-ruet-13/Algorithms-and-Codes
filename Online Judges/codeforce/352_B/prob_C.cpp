#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int arr[100];

    long long n;
    string str;

    cin>>n;

    cin>>str;


    memset(arr,0,sizeof(arr));

    if(str.size() > 26 )
       {

       cout<<-1<<endl;
        return 0;
       }

    for(int i=0; i<str.size() ; i++)
    {
        arr[str[i]-'a']++;
    }

    int cnt;

    cnt=0;

    for(int i=0 ;i<26 ;i++)
    {
        if(arr[i]>1)
            cnt+=arr[i]-1;
    }


    cout<<cnt<<endl;




    return 0;

}

