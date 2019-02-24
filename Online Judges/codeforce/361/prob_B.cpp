#include<iostream>
#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
#define pi acos(-1.0000)

using namespace std;

int main()
{

    ll n;

    int arr[20];
    memset(arr,0,sizeof(arr));

    string str;


    cin>>n;

    cin>>str;

    for(int i=0;i<str.size() ; i++)
    {
        arr[str[i]-'0']=1;
    }

    if((arr[1]&& arr[9])  ||  (arr[3]&& arr[7]) || (arr[1]&& arr[0]) || (arr[3]&& arr[0]) || (arr[2]&& arr[0]) || ((arr[1]|| arr[4] || arr[7])&&(arr[3]&& arr[9])) || ((arr[3]|| arr[6] || arr[9])&&(arr[1]&& arr[7])) )
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;




     return 0;
}

