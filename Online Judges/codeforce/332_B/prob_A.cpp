#include<iostream>
#include<bits/stdc++.h>

#define pi acos(-1.0000);
#define rep(x,n) for(int i=x;i<=n;i++)
#define LL long long
#define pb(x) push_back(x)
#define valid(x,y) (x>=0 && x<row && y>=0 && y<col)
#define mem(x,y) memset(x,y,sizeof(x))
#define uu first
#define vv second
#define pii pair<int,int>

using namespace std;

int main()
{
    long long int d1,d2,d3,temp1,temp2,temp3,temp4,temp;

    cin>>d1>>d2>>d3;

    temp1=(2*d1)+(2*d2);
    temp2=d1+d3+d2;
    temp3=2*d1+2*d3;
    temp4=2*d2+2*d3;

    temp=min(temp1,temp2);
    temp=min(temp,temp3);
    temp=min(temp,temp4);

    cout<<temp<<endl;

    return 0;
}
