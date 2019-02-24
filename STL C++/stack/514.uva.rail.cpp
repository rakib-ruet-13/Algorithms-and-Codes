#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,num;
    vector<int>vct,vct2;

    while(cin>>n && n)
    {
        for(int m=0;m<n;m++)
        {

         vct.clear();
         vct2.clear();
        cin>>num;
        if(num==0)
        {
            cout<<endl;

            break;
        }
        int cnt=1;

        vct.push_back(num);

        for(int i=1;i<n;i++)
        {
            cin>>num;
            vct.push_back(num);
        }
        reverse(vct.begin(),vct.end());

        for(int i=1;i<=n;i++)
        {
            vct2.push_back(i);
            while(vct.back()==vct2.back() && !(vct.empty()))
            {
                vct.pop_back();
                vct2.pop_back();
            }
        }


        if(vct.empty())
        {
            cout<<"Yes"<<endl;

        }
        else
            cout<<"No"<<endl;
        }

    }
}
