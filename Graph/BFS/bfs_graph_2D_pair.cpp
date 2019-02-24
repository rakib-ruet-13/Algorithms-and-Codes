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

int row,col;
int cell[1001][1001];
int visited[1001][1001];
int dis[1001][1001];


int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

void bfs(int sx,int sy)
{
    mem(visited,0);
    queue<pii>q;

    visited[sx][sy]=1;
    dis[sx][sy]=0;

    q.push(pii(sx,sy));


    while(!(q.empty()))
    {
          pii top=q.front();



          for(int k=0;k<4;k++)
          {
              int xx=top.uu+fx[k];
              int yy=top.vv+fy[k];

              if(valid(xx,yy) && visited[xx][yy]==0)
              {

                  dis[xx][yy]=dis[top.uu][top.vv]+1;
                  visited[xx][yy]=1;
                  q.push(pii(xx,yy));
              }
          }
          q.pop();
    }


}
int main()
{
    int sx,sy,dx,dy;
    cin>>row>>col;
    cin>>sx>>sy;
    cin>>dx>>dy;

    bfs(sx,sy);
    cout<<dis[dx][dy];


}
