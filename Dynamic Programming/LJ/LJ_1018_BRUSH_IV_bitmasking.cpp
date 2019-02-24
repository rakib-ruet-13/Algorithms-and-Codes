#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{ int x, y ;}point[17];
int n;
int dp[1<<17];

int comp[18][18];

int Set(int n,int pos) { return n | 1<<pos ;}
bool check(int n,int pos) { return n & 1<<pos;}

bool tri_angle(node a, node b, node c)
{
    long long area= a.x* (b.y-c.y ) - a.y*(b.x-c.x) + b.x*c.y-c.x*b.y;

    if(area==0)
        return true;
    else
        return false;
}

int pop_count(int mask)
{
    int cnt=0;
    for(int i=0; i<n ; i++)
    {
        if(!check(mask,i))
            cnt++;
    }

    return cnt;
}


int solve(int mask)
{

    if(mask>=((1<<n)-1))
        return 0;

    if(pop_count(mask)==1)
        return 1;

    if(dp[mask]!=-1)
        return dp[mask];

        int mn=1000000;

        for(int i=0; i<n ; i++)
        {
            if(!check(mask,i))
            {
                for(int j=0; j<n ; j++)
                {
                    int res=0;
                    if(i!=j && !check(mask,j))
                     {
                         res=1+solve(mask | comp[i][j]);

                         mn=min(mn,res);
                     }

                }

                  break;
            }


        }

        return dp[mask]=mn;





}



int main()
{


    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ; cs++)
    {
        scanf("%d",&n);

        for(int i=0; i<n ;i++)
        {
            scanf("%d %d",&point[i].x,&point[i].y);
        }

        for(int i=0; i<n ;i++)
            for(int j=i+1; j<n ; j++)
        {
            int temp=0;

            for(int k=0; k<n ; k++)
            {
                if(tri_angle(point[i],point[j],point[k]))
                {
                    temp=Set(temp,k);
                }
            }

            comp[i][j]=comp[j][i]=temp;


        }

        memset(dp,-1,sizeof(dp));
        int res=0;
        res=solve(0);


        printf("Case %d: %d\n",cs,res);
    }
    return 0;
}
