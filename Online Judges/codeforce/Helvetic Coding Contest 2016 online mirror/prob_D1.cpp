#include<iostream>
#include<bits/stdc++.h>
#define inf 99999999999999
#define pb push_back
#define pi acos(-1.000)
#define all(x) (x.begin(),x.end())
#define VI vector<long long>

using namespace std;

typedef long long ll;


int main()
{
    ll n;
    int row,col;
    cin>>row>>col;
    string str;
    for(int i=1;i<=row;i++)
    {
        cin>>str;
    }


    bool flag=0;

    ll cnt=0;

    for(int i=0;i<str.size() ;i++)
    {
        if(flag==0 && str[i]=='B')
        {
            cnt++;
            flag=1;
        }

        if(str[i]=='.')
            flag=0;
    }


    cout<<cnt<<endl;








    return 0;
}

