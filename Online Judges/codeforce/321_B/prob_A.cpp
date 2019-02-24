#include<iostream>
#include<bits/stdc++.h>

#define valid(x,y) (x>=1 && x<=col && y>=1 && y<=row)
#define pb(x) push_back(x)
#define pi acos(-1.0000)
#define ll long long

using namespace std;
int main()
{
    long long int n,sum,num;

    long long int mx=0;
    long long int pre=-1;

    cin>>n;
    int cnt=0;

    for(int i=0;i<n;i++)
    {
        cin>>num;

        if(num>=pre)
            cnt++;
        else
            cnt=1;

        pre=num;

        if(cnt>mx)
            mx=cnt;

    }

    cout<<mx<<endl;




    return 0;


}
