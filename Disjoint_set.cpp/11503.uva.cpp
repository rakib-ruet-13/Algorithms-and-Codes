#include<iostream>
#include<bits/stdc++.h>

using namespace std;

map<string,string>par;
map<string,int>cnttt;

string find(string str)
{
    if(par[str]==str)
        return str;
    return par[str]=find(par[str]);
}
int main()
{
    int tc;

    cin>>tc;

    while(tc--)
    {

        int cnt=0;
        int n;
        scanf("%d",&n);

        string str1,str2;



        for(int i=0;i<n;i++)
        {
            cin>>str1>>str2;



            if(cnttt[str1]==0)
          {
              cnttt[str1]++;
              par[str1]=str1;
              cnt++;
          }

          if(cnttt[str2]==0)
          {
              cnttt[str2]++;
              par[str2]=str2;
              cnt++;
          }

            string u=find(str1);
            string v=find(str2);

            if(u!=v)
            {
                par[u]=v;
                cnttt[v]=cnttt[u]+cnttt[v];
            }

            cout<< cnttt[v]<<endl;


        }
         par.clear();
         cnttt.clear();


    }



}
