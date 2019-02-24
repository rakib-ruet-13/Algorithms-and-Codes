#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll inf;
ll Max;

char arr[102][102];
int main()
{
    inf=100000000000000000;

    ll n,m;

    cin>>n>>m;

    int flag=0;

    for(int i=1; i<=n ;i++)
        for(int j=1; j<=m ;j++)
    {
        char ch;
        cin>>ch;

        if(ch=='W' || ch=='B' || ch=='G');
        else
            flag=1;

    }

    if(!flag)
        cout<<"#Black&White"<<endl;
    else
        cout<<"#Color"<<endl;




    return 0;
}
