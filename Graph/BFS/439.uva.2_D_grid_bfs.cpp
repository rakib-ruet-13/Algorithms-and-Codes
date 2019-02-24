#include<iostream>
#include<bits/stdc++.h>

#define pi acos(-1.0000);
#define rep(x,n) for(int i=x;i<=n;i++)
#define LL long long
#define pb(x) push_back(x)
#define valid(x,y) (x>=1 && x<=row && y>=1 && y<=col)
#define mem(x,y) memset(x,y,sizeof(x))
#define uu first
#define vv second
#define pii pair<int,int>

using namespace std;
int bfs_2_D(int sx,int sy,int dx,int dy);

int fx[]={2,2,-2,-2,1,1,-1,-1};
int fy[]={1,-1,1,-1,2,-2,2,-2};

int cell[10][10];
int visited[10][10];
int dis[10][10];
int row=8,col=8;

int main()
{
    int y1,y2,sx,sy,dx,dy;
    char x1,x2;

    while(cin>>x1>>y1>> x2>>y2)
    {
       sx=x1-'a'+1;
       sy=y1;
       dx=x2-'a'+1;
       dy=y2;

       printf("To get from %c%d to %c%d takes %d knight moves.\n",x1,y1,x2,y2,bfs_2_D(sx,sy,dx,dy));

    }

}
int bfs_2_D(int sx,int sy,int dx,int dy)
{
    for(int i=0;i<10;i++)
        mem(visited[i],0);

    for(int i=0;i<10;i++)
        mem(dis[i],0);

    queue<pii>q;
    visited[sx][sy]=1;
    dis[sx][sy]=0;

    q.push(pii(sx,sy));

    while(!q.empty())
    {
        pii top=q.front();
        q.pop();

        for(int k=0;k<8;k++)
        {
            int xx=top.uu+fx[k];
            int yy=top.vv+fy[k];

            if(valid(xx,yy))
                if(visited[xx][yy]!=1)
            {
                visited[xx][yy]=1;
                dis[xx][yy]=dis[top.uu][top.vv]+1;
                q.push(pii(xx,yy));
                if(xx==dx && yy==dy)
                    return dis[xx][yy];

            }
        }

    }
    return dis[dx][dy];

}
