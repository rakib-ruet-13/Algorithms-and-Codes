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
#define inf 10010000

using namespace std;

int bfs(int sx,int sy);

int row,col;
char cell[502][502];
int visited[502][502];
int level[502][502];

int desx,desy;

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

int cnt=0;

int bfs(int sx,int sy)
{
    mem(visited,0);
    queue<pii>q;

    cnt=0;

    if(cell[sx][sy]=='C')
        cnt++;

    visited[sx][sy]=1;
    q.push(pii(sx,sy));


    while(!(q.empty()))
    {
          pii top=q.front();



          for(int k=0;k<4;k++)
          {
              int xx=top.uu+fx[k];
              int yy=top.vv+fy[k];

              if(valid(xx,yy) && visited[xx][yy]==0 && cell[xx][yy]!='#')
              {
                  visited[xx][yy]=1;

                  if(cell[xx][yy]=='C')
                    cnt++;

                  q.push(pii(xx,yy));
              }
          }
          q.pop();
    }

    while(!q.empty());
    q.pop();

    return 1;


}



void dfs(int ux,int uy)
{

    level[ux][uy]=cnt;

    //int mx=0;

    //if(cell[ux][uy]=='C')
       // mx++;


          for(int k=0;k<4;k++)
          {
              int xx=ux+fx[k];
              int yy=uy+fy[k];

              if(valid(xx,yy) && level[xx][yy]==-1 && cell[xx][yy]!='#')
              {
                  dfs(xx,yy);
              }


          }
}


int main()
{
    int tc,sx,sy;
    char ch;

    scanf("%d",&tc);
    for(int cs=1;cs<=tc;cs++)
    {

        int q;
        scanf("%d %d %d",&row,&col,&q);

        getchar();
        for(int i=1;i<=row;i++)
        {

            for(int j=1;j<=col;j++)
        {
            scanf("%c",&ch);
            cell[i][j]=ch;
        }

        getchar();

        }

        memset(level,-1,sizeof(level));

        for(int i=1; i<=row ;i++)
            for(int j=1; j<=col ;j++)
        {

            if(level[i][j]==-1 && cell[i][j]!='#')
            {
                cnt=0;

                bfs(i,j);
                dfs(i,j);
            }

        }

        // cout<<"ok"<<endl;


          printf("Case %d:\n",cs);

          while(q--)
          {
              int a,b;
              scanf("%d %d",&a,&b);
              printf("%d\n",level[a][b]);
          }

    }

    return 0;

}

