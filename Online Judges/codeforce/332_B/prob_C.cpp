#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    vector<int>vct;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        vct.push_back(x);
    }

    sort(vct.begin(),vct.end());

    int cnt=0;
    int x=0;
    int temp=-1;
    for(int i=0;i<n-1;i++)
    {
        if(vct[i]==vct[i+1])
        {
            if(temp!=vct[i])
            {
                x++;
                temp=vct[i];
            }

            cnt++;
        }
    }
    if(cnt>0)
    cout<<n-cnt-x<<endl;

    if(cnt==0)
        cout<<n<<endl;


}
