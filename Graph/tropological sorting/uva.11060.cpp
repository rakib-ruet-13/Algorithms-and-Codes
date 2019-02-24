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
pair<int,string>p;

priority_queue<pair<int,string> , vector< pair<int,string > > , greater<pair<int,string> > > q;
map<string,int>pos;

int main()
{


    int cs=1;

    int node,edge;

     while(cin>>node)
    {

        rep(i,1,node)
        {
            string st;
            cin>>st;
            pos[st]=i;

            ind[st]=0;
        }

        cin>>edge;

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
                q.push(pair<int,string>(pos[it->first],it->first));
        }


        vector<string>res;

        while(!q.empty())
        {
            pair<int,string > t;
            t= q.top();
            res.push_back(t.second);
            q.pop();
            for(int i=0; i<graph[t.second].size() ; i++)
            {
                ind[graph[t.second][i]]--;
                string s=graph[t.second][i];

                if(ind[s]==0)
                    q.push(pair<int,string>(pos[graph[t.second][i]],graph[t.second][i]));
            }
        }


        printf("Case #%d: Dilbert should drink beverages in this order:",cs++);

        for(int i=0;i<res.size() ;i++)
        {

                cout<<" "<<res[i];
        }

        cout<<"."<<endl<<endl;

        graph.clear();
        res.clear();
        ind.clear();


    }





}

