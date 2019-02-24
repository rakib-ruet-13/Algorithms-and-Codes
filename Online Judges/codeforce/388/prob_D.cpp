#include<iostream>
#include<bits/stdc++.h>
#define inf 1000010000
using namespace std;


char buff[1001000];

map<string, priority_queue<long long> >mymap;
map<string, priority_queue<long long> > :: iterator it;
priority_queue<long long>vct;

int main()
{


    int n,k;
    long long cost;
    string str;

    scanf("%d %d",&n,&k);

    for(int i=0; i<n ;i++)
    {
     scanf("%s %lld",&buff,&cost);

     str=buff;
     mymap[str].push(cost);

    }
    long long res=0;


    for(it=mymap.begin(); it!=mymap.end() ;it++)
    {
        string s=it->first;
        string revs=s;

        reverse(revs.begin(),revs.end());

        if(revs==s)
        {

            while(1)
            {

            long long int p=-inf;
            long long int q=-inf;

            int cnt=0;


            if(!mymap[s].empty())
              {
                  p=mymap[s].top();
                  mymap[s].pop();
                  cnt++;
              }

             if(!mymap[s].empty())
              {
                  q=mymap[s].top();
                  mymap[s].pop();
                  cnt++;
              }

            if(p+q<=0)
            {
                if(cnt>=1)
                    mymap[s].push(p);
                if(cnt>1)
                    mymap[s].push(q);
                break;
            }
            else
            {
                res+=(p+q);
                if(min(p,q)<0)
                vct.push(-min(p,q));
            }

           }
        }
        else
        {

             while(1)
            {

            long long int p=-inf;
            long long int q=-inf;

            int cnt=0;


            if(!mymap[s].empty())
              {
                  p=mymap[s].top();
                  mymap[s].pop();
                  cnt++;
              }

             if(!mymap[revs].empty())
              {
                  q=mymap[revs].top();
                  mymap[revs].pop();
                  cnt++;
              }

            if(p+q<=0)
            {
                if(cnt>=1)
                    mymap[s].push(p);
                if(cnt>1)
                    mymap[revs].push(q);
                break;
            }
            else
            {
                res+=(p+q);

                // if(min(p,q)<0)
                //vct.push(-min(p,q));
            }



        }


    }
    }

    long long mx=0;

     if(!vct.empty())
     mx=max(mx,vct.top());

        for(it=mymap.begin(); it!=mymap.end() ;it++)
        {
            string p=it->first;
            string q=p;
            reverse(q.begin(),q.end());

            if(!mymap[p].empty() && p==q)
            {
                mx=max(mx,mymap[p].top());
            }

        }

        res+=mx;

        printf("%lld\n",res);







    return 0;
}
