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

int bfs_2D_grid(int sx,int sy);

int row,col;
char cell[22][22];
int visited[22][22];
//int dis[22][22];

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

int main()
{
    int tc,sx,sy;
    char ch;

    scanf("%d",&tc);
    for(int cs=1;cs<=tc;cs++)
    {
        cin>>col>>row;

        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++)
        {
            cin>>ch;
            cell[i][j]=ch;
            if(ch=='@')
            {
                sx=i;
                sy=j;
            }

        }

        printf("Case %d: %d\n",cs,bfs_2D_grid(sx,sy));
    }



}


int bfs_2D_grid(int sx,int sy)
{
    mem(visited,0);

    queue<pii>q;

    visited[sx][sy]=1;
    int cnt=1;

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


                if(cell[xx][yy]=='.')
                  if(visited[xx][yy]==0)
            {
                visited[xx][yy]=1;
                q.push(pii(xx,yy));
                cnt++;

            }
            }

        }
    }

    return cnt;

}


