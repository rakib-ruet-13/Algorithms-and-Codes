#include<iostream>
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pi acos(-1.000)
#define pb push_back

using namespace std;

string str;
vector<long long>vct;

int arr[100100];

int main()
{
    long long n,h;
    cin>>n>>h;

    long long cnt=0;

    for(int i=1;i<=n ;i++)
    {
        long long a;
        cin>>a;

        if(a>h)
            cnt+=2;
        else
           cnt+=1;
    }



    cout<<cnt<<endl;


    return 0;
}
