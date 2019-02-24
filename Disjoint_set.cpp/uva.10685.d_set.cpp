#include<iostream>
#include<bits/stdc++.h>

using namespace std;

map<string,string>par;
map<string,int>cnt;

string find(string str)
{
    if(par[str]==str)
        return str;
        return par[str]=find(par[str]);
}


int main()
{
    map<string,string>str;
    map<string,string>::iterator it;

    int n,t;

    while(scanf("%d %d",&n,&t)==2)
    {
        if(n==0)
            break;

        for(int i=1;i<=n;i++)
        {
           string s;
           cin>>s;
           par[s]=s;
           cnt[s]=1;
        }

        string str1,str2;

        for(int i=1; i<=t ;i++)
        {
            cin>>str1>>str2;

            string u=find(str1);
            string v=find(str2);

            if(u!=v)
            {

                par[u]=v;
                cnt[v]=cnt[u]+cnt[v];

            }
        }

        int mx=-1111;

        for( it=par.begin(); it!=par.end();it++)
        {

                mx=max(mx,cnt[it->first]);
        }

        printf("%d\n",mx);
        par.clear();
        cnt.clear();

    }



}
