#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);
    for( int cs=1 ; cs<=tc ;cs++)
    {

        int n;
        scanf("%d",&n);

        printf("Case %d:\n",cs);

        int sum=0;

        for(int i=1; i<=n ;i++)
        {
        string str;
        cin>>str;

        if(str[0]=='d')
        {
            int a;
            cin>>a;
            sum+=a;
        }
        else
        {
            cout<<sum<<endl;
        }

        }


    }



}
