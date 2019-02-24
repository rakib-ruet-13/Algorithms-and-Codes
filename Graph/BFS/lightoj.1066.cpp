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
#define inf 100100

using namespace std;

int bfs(int sx,int sy);

int row,col;
char cell[15][15];
int visited[15][15];
int dis[22][22];

int desx,desy;

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};



int bfs(int sx,int sy)
{
    mem(visited,0);

    for(int i=0; i<=row; i++)
        for(int j=0; j<=col ;j++)
    {
        dis[i][j]=inf;
    }
    queue<pii>q;

    visited[sx][sy]=1;
    dis[sx][sy]=0;
    cell[desx][desy]='.';
    q.push(pii(sx,sy));


    while(!(q.empty()))
    {
          pii top=q.front();



          for(int k=0;k<4;k++)
          {
              int xx=top.uu+fx[k];
              int yy=top.vv+fy[k];

              if(valid(xx,yy) && visited[xx][yy]==0 && cell[xx][yy]=='.')
              {

                  dis[xx][yy]=dis[top.uu][top.vv]+1;
                  visited[xx][yy]=1;
                  q.push(pii(xx,yy));
              }
          }
          q.pop();
    }

    while(!q.empty());
    q.pop();

    cell[desx][desy]=cell[sx][sy]+1;
    cell[sx][sy]='.';
    return dis[desx][desy];


}


int main()
{
    int tc,sx,sy;
    char ch;
    int k;

    scanf("%d",&tc);
    for(int cs=1;cs<=tc;cs++)
    {
        scanf("%d",&row);
        col=row;
        k=0;

        int res=0;

        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++)
        {
            cin>>ch;

            if(ch!='#' && ch!='.')
                k++;

            cell[i][j]=ch;
        }

         char p='A';

        for(int i=1; i<k; i++)
        {


        for(int i=1; i<=row; i++)
            for(int j=1; j<=col; j++)
        {
            if(cell[i][j]==p)
            {
                sx=i;
                sy=j;
            }

            if(cell[i][j]==p+1)
            {
                desx=i;
                desy=j;
            }

        }

          res+=bfs(sx,sy);

          if(res>inf)
            break;

          p++;

        }

        if(res<inf)
        printf("Case %d: %d\n",cs,res);
        else
            printf("Case %d: Impossible\n",cs);
    }



}

