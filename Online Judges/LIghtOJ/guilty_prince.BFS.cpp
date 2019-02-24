#include<iostream>
#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define pii pair<int,int>
#define mem(a,val) memset(a,val,sizeof(a))
#define long long ll
#define valid(x,y) (x>=1 && x<=row && y>=1 && y<=col)
#define Max 100000
#define mp make_pair

using namespace std;


char graph[22][22];
int visited[22][22];
int level[22][22];

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int row,col;

int bfs(int sx,int sy,int node)
{
    for(int i=0;i<22;i++)
        mem(visited[i],0);
     for(int i=0;i<22;i++)
        mem(level[i],0);


    pii p;

    queue<pii>q;

    q.push(pii(sx,sy));


     visited[sx][sy]=1;
      level[sx][sy]=0;



    while(!q.empty())
    {
        p=q.front(); q.pop();

        for(int k=0; k<4;k++)
        {
            int xx=p.first+fx[k];
            int yy=p.second+fy[k];

            if(valid(xx,yy))
            {
                if(visited[xx][yy]==0 && graph[xx][yy]!='#')
                {
                    visited[xx][yy]=1;
                    level[xx][yy]=level[p.first][p.second]+1;


                    q.push(mp(xx,yy));
                }
            }
        }

    }

    int cnt=0;
    for(int i=1; i<=row;i++)
        for(int j=1; j<=col ;j++)
    {
        if(level[i][j]>0)
            cnt++;
    }

    return cnt;

}


int main()
{
    //freopen("input.txt","r",stdin);
    int tc;
    int sx,sy,i,j;
    char ch;
    scanf("%d",&tc);

    string str;

    for(int cs=1 ;cs<=tc ;cs++)
    {
        scanf("%d %d",&col,&row);

        for( i=1; i<=row ;i++)
        {
          for(j=1 ;j<=col ;j++)
            {
               cin>>ch;
               graph[i][j]=ch;

              if(graph[i][j]=='@')
              {
                  sx=i;
                  sy=j;
              }
            }
        }

        printf("Case %d: %d\n",cs,bfs(sx,sy,100)+1);
    }

}
