#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool p;

map<string,int>visited;
map<string,vector<string> >graph,rev_graph;
map<string,vector<string> >:: iterator it;
int t;

stack<string>stk;

void dfs(string str)
{
    visited[str]=1;
    for(int i=0 ; i<graph[str].size(); i++)
    {
        string s=graph[str][i];
        if(visited[s]==0)
            dfs(s);
    }

    stk.push(str);
}



void rev_dfs(string str)
{
    visited[str]=1;
    for(int i=0 ; i<rev_graph[str].size(); i++)
    {
        string s=rev_graph[str][i];

        if(visited[s]==1)
            {

            }

        if(visited[s]==0)
            {
                rev_dfs(s);
                  p=false;
            }
    }

    //stk.push(str);
}



int main()
{


    int n;
    string str1,str2;
    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {

        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
           cin>>str1>>str2;
           graph[str1].push_back(str2);
           rev_graph[str2].push_back(str1);
        }

        p=true;

        /**** clearing for graph ***/
        for(it=graph.begin() ; it!=graph.end() ;it++)
        {
            visited[it->first]=0;
        }

        for(it=graph.begin() ; it!=graph.end() ;it++)
        {
            if(visited[it->first]==0)
               {
                   dfs(it->first);
               }
        }
        /******claring for rev graph****/

          for(it=graph.begin() ; it!=graph.end() ;it++)
        {
            visited[it->first]=0;
        }


        while(!stk.empty())
        {
            string ss=stk.top();
            stk.pop();

           // cout<<ss<<endl;

            if(visited[ss]==0)
            {
                rev_dfs(ss);
            }

        }

        if(p)
            printf("Case %d: Yes\n",cs);
        else
            printf("Case %d: No\n",cs);


        graph.clear();
        rev_graph.clear();
        visited.clear();
        //stime.clear();

    }
          return 0;

}
