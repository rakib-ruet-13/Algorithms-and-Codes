#include<iostream>
#include<bits/stdc++.h>
using namespace std;


#define Max 1010
#define pb(x) push_back(x)
#define ll long long
#define pi acos(-1.000)
#define valid(x,y) (x>=1 && x<=row && y>=1 && y<=col)
#define uu first
#define vv second
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define mod 1000000007
#define pii pair<ll,ll>
#define pipii pair<int,pii >
#define inf INFINITY


using namespace std;

int bfs_2D_grid(int sx,int sy,int dx,int dy);

int row,col;
int cell[1001][1001];
int visited[1001][1001];
int dis[1001][1001];

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

int main()
{
    int tc,sx,sy,dx,dy,r,rn,cnt,pos,mines;

       while(cin>>row>>col && row && col)
       {
          cin>>r;


        for(int i=0;i<r;i++)
        {
             cin>>rn;
             cin>>mines;

             for(int j=1;j<=mines;j++)
             {
                 cin>>pos;
                 cell[rn][pos]=1;
             }

        }

        cin>>sx>>sy;
        cin>>dx>>dy;

        cout<<bfs_2D_grid(sx,sy,dx,dy)<<endl;

        for(int i=0;i<1001;i++)
        mem(dis[i],0);
          for(int i=0;i<1001;i++)
            mem(cell[i],0);

    }



}


int bfs_2D_grid(int sx,int sy,int dx,int dy)
{
    for(int i=0;i<1001;i++)
    mem(visited[i],0);

    queue<pii>q;

    visited[sx][sy]=1;
    dis[sx][sy]=0;


    q.push(pii(sx,sy));

    while(!q.empty())
    {
        pii top=q.front();
        q.pop();

        for(int k=0;k<4;k++)
        {
            int xx=top.uu+fx[k];
            int yy=top.vv+fy[k];

            if(valid(xx,yy))
            {


                if(cell[xx][yy]!=1)
                  if(visited[xx][yy]==0)
            {

                visited[xx][yy]=1;
                dis[xx][yy]=dis[top.uu][top.vv]+1;


                if(xx==dx && yy==dy)
                    return  dis[xx][yy];

                q.push(pii(xx,yy));

            }

            }

        }
    }
    return dis[dx][dy];

}



