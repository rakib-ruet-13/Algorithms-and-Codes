#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define pi acos(-1.0000000000)

struct point{ ll x; ll y;};
point p0;
point base;

point arr[2001];
int N,M;

vector<point>hull;

vector<int>graph[1001];

long long distSq(point p1, point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}




long long orientation(point p, point q, point r)
{
    long long val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: -1; // clock or counterclock wise
}

bool comp(point p1,point p2)
{
   int o = orientation(p0,p1,p2);

   if(o==0)
   {
     return (distSq(p0, p1) < distSq(p0, p2));
   }

   return (o == 1)? 0 :1;
}



void select_base_point()
{
    int loc=0;
    point temp=arr[0];
    for(int i=0; i<N ; i++)
    {
        if(arr[i].y<temp.y || (arr[i].y==temp.y &&  arr[i].x<temp.x))
        {
            loc=i;
            temp=arr[i];
        }

    }
    swap(arr[0],arr[loc]);
    base=arr[0];
    p0=arr[0];


}




void graham_scan()
{
    select_base_point();

    sort(arr+1,arr+N,comp);


    hull.clear();

    hull.push_back(arr[0]);
    hull.push_back(arr[1]);

    for(int i=2; i<N; i++)
    {
        int sz=hull.size();



        if(orientation(hull[sz-2],hull[sz-1],arr[i])<0)
        {
            hull.push_back(arr[i]);
        }
        else
        {
            //cout<<"i== "<<i<<endl;

            while(1)
            {
                sz=hull.size();
                 if(sz==1)
                 {
                    hull.push_back(arr[i]);
                    break;
                 }

                hull.pop_back();
                sz=hull.size();

                if(sz>1)
                {

                    if(orientation(hull[sz-2],hull[sz-1],arr[i])<0 )
                    {
                        hull.push_back(arr[i]);
                        break;
                    }

                }

            }
        }
    }


}


int inside(point pp,vector<point>hull_new)
{

    int sz=hull_new.size();

    if(sz<3)
        return 0;

    int flag=1;

    for(int i=1; i<sz ; i++)
    {
        if(orientation(hull_new[i-1],hull_new[i],pp) != -1)
        {
            flag=0;
            break;
        }
    }

    if(orientation(hull_new[sz-1],hull_new[0],pp) != -1)
        flag=0;

    return flag;

}

point mine[1001];


int bfs(int n,int src)
{

    queue<int>Q;
    int visited[1005],level[1005];

    memset(visited,0,sizeof(visited));
    for(int i=0; i<=1000; i++)
      level[i]=1000;


    for(int i=0; i<graph[src].size() ; i++)
    {
        Q.push(graph[src][i]);
        level[graph[src][i]]=1;
        visited[graph[src][i]]=1;
    }

    while(!(Q.empty()))
    {
        int u=Q.front();
        for(int i=0;i<graph[u].size();i++)
        {
           int  v=graph[u][i];

            if(visited[v]==0)
            {
                level[v]=level[u]+1;
                visited[v]=1;
                Q.push(v);


            }

        }
        Q.pop();


    }

    while(!Q.empty())
        Q.pop();

    return level[src];

}

int main()
{

    int tc;
    scanf("%d",&tc);

    ll G,P;

    for(int cs=1 ; cs<= tc ; cs++)
    {

        scanf("%d %d %lld %lld",&N,&M,&G,&P);

        for(int i=0; i<N ; i++)
        scanf("%lld %lld",&arr[i].x,&arr[i].y);

        graham_scan();



        int k=0;

        point temp;
        for(int i=0; i<M; i++)
        {
             scanf("%lld %lld",&temp.x,&temp.y);

             if(inside(temp,hull))
                {
                    mine[k++]=temp;
                }

        }


         long long res=0;
         res+=G*(M-k);

            for(int i=0; i<hull.size() && k>0 ; i++)
                for(int j=i+1; j<hull.size() && k>0; j++)
            {

                int flag=1;
                for(int p=0; p<k ; p++)
                {
                        if(orientation(hull[i],hull[j],mine[p]) == 1)
                        {
                            flag=0;
                            break;

                        }
                }
                if(flag==1)
                {
                    graph[i].push_back(j);

                }



               flag=1;
                for(int p=0; p<k ; p++)
                {
                        if(orientation(hull[j],hull[i],mine[p]) != -1)
                        {
                            flag=0;
                            break;

                        }
                }
                if(flag==1)
                {
                    graph[j].push_back(i);

                }

            }


            int need=111;

            for(int z=0 ; z<hull.size() ; z++)
            {
                need=min(need,bfs(hull.size(),z));

            }




        res=res+P*need;

        for(int i=0; i<1000; i++)
            graph[i].clear();


        res=min(res,G*M);

        printf("Case %d: %lld\n",cs,res);




        }



    return 0;
}



