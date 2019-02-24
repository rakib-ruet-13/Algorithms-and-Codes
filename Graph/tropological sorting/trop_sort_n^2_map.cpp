#include<iostream>
#include<bits/stdc++.h>
#define read32(x) scanf("%d",&x)
#define read64(x) scanf("%lld",&x)
#define rep(i,a,b)  for(int i=a ;i<=b; i++)
//#define rep(i,n) for(int i=1; i<=n;i++)

using namespace std;

map<string,int>ind;
map<string,int>::iterator it;
map<string,vector<string> > graph;
queue<string>q;

int main()
{
    int tc;

    read32(tc);


    rep(cs,1,tc)
    {
        int node,edge;

        read32(node);
        read32(edge);

        rep(i,1,edge)
        {
            string u,v;
            cin>>u;
            cin>>v;
            graph[u].push_back(v);

            ind[u]+=0;
            ind[v]+=1;
        }


        for(it=ind.begin() ;it!=ind.end() ;it++)
        {
            if(it->second==0)
                q.push(it->first);
        }


        vector<string>res;

        while(!q.empty())
        {
            string t=q.front();
            res.push_back(t);
            q.pop();
            for(int i=0; i<graph[t].size() ; i++)
            {
                ind[graph[t][i]]--;
                string s=graph[t][i];

                if(ind[s]==0)
                    q.push(graph[t][i]);
            }
        }

        for(int i=0;i<res.size() ;i++)
        {
            if(i==0)
            cout<<res[i];
            else
                cout<<" "<<res[i];
        }

        cout<<endl;


    }





}
