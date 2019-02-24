#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,tc,a,b,arr[100],arr2[100];
    vector<int>vct;

    cin>>n;

    for(int i=0;i<100;i++)
    {
        arr[i]=0;
        arr2[i]=0;
    }

    for(int i=1;i<=n*n;i++)
    {
        cin>>a>>b;

        if(arr[a]==0 && arr2[b]==0)
        {
            arr[a]=1;
            arr2[b]=1;
            vct.push_back(i);
        }



    }

    sort(vct.begin(),vct.end());
    for(int i=0;i<vct.size();i++)
        cout<<vct[i]<<" ";

        cout<<endl;
    cout<<endl;

}
