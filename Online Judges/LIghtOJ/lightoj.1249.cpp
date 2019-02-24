#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<pair<int,string> >vct;

bool comp ( pair<int,string> a, pair<int,string> b)
{
    return a.first < b.first;
}

int main()
{
    int tc;
    cin>>tc;

    //freopen("out.txt","w",stdout);

    for(int cs=1 ; cs<= tc ; cs++)
    {
        int n;
        cin>>n;


        for(int i=1; i<=n ;i++)
        {
            int l,w,h;
            string str;

            cin>>str;
            cin>>l>>w>>h;
            int v;
            v=l*w*h;
            vct.push_back(make_pair(v,str));
        }

        sort(vct.begin(),vct.end(),comp);


        printf("Case %d: ",cs);

        if(vct[0].first < vct[vct.size()-1].first)
            cout<<vct[n-1].second<<" took chocolate from "<<vct[0].second<<endl;
        else
           cout<<"no thief\n";

           vct.clear();

    }

    return 0;
}
