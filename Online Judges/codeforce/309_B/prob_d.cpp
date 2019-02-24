#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
    long long int n,m,num;

    vector<long int>vct;

    while(cin>>n>>m)
    {

        for(int i=0;i<m;i++)
        {
            cin>>num;
            vct.push_back(num);

        }

        sort(vct.begin(),vct.end());

        int mx=0;
        for(int i=1;i<n;i++)
        {
            mx+=(vct[i]-vct[i-1]);
        }
        //cout<<mx<<endl;
        int mx1;
        mx1=mx;
        for(int i=n;i<m;i++)
        {
            //cout<<vct[i-n+1]-vct[i-n]<<" ";
            //cout<<vct[i]-vct[i-1];
            //cout<<endl;

                mx=mx+(vct[i]-vct[i-1])-(vct[i-n+1]-vct[i-n]);

                mx1=min(mx1,mx);
        }

        cout<<mx1<<endl;

    }


}
