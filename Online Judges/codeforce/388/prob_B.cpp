#include<iostream>
#include<bits/stdc++.h>

using namespace std;

map<char,int>mp;

string s1,s2;
set< pair<char,char> >res,res1;
set< pair<char,char> >:: iterator it;

int main()
{
    cin>>s1>>s2;

    for(int i=0; i<s1.size();i++)
    {

           char ch1=s1[i];
           char ch2=s2[i];

           if(ch1>ch2)
                swap(ch1,ch2);
           res.insert(make_pair(ch1,ch2));
    }


    bool flag=1;

        for(it=res.begin(); it!=res.end() ;it++)
        {
            pair<char,char>pp;
            pp=*it;
            mp[pp.first]++;
            mp[pp.second]++;

             if(pp.first==pp.second)
                mp[pp.first]--;

            if(pp.first!=pp.second)
                res1.insert(pp);

            if(mp[pp.first]>1 ||  mp[pp.second]>1)
                flag=0;
        }


    if(!flag)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<res1.size()<<endl;

        for(it=res1.begin(); it!=res1.end() ;it++)
        {
            pair<char,char>pp;
            pp=*it;
            cout<<pp.first<<" "<<pp.second<<endl;
        }

    }



    return 0;
}


