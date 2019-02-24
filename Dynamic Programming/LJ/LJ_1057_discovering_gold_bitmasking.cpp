#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int check(int N,int pos){ return N&(1<<pos);}
int Set(int N,int pos){ return N=(N|(1<<pos));}
int Reset(int N,int pos){ return N=(N & ~(1<<pos));}

int dp[17][1<<17];
int N;

struct node
{
    int x;
    int y;
}point[18];

int dis(node a,node b)
{
    return max(abs(a.x-b.x),abs(a.y-b.y));
}


long long solve(int pre,int mask)
{


    if(mask== ((1<<N) -1))
        return dis(point[0],point[pre]);

    if(pre>N)
        return dis(point[0],point[pre]);;

    if(dp[pre][mask]!=-1)
        return dp[pre][mask];

    int mn=11111111;



    for(int i=0; i<N; i++)
    {
        int res=11111111;

        if(mask==0)
        {
            res=solve(pre,Set(mask,pre));
             mn=min(mn,res);
             break;
        }


        if( !check(mask,i))
        {
            res=dis(point[pre],point[i])+solve(i,Set(mask,i));

        }
        mn=min(mn,res);

    }

    return dp[pre][mask]=mn;

}


int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
        int n,m;

        scanf("%d %d",&n,&m);

        N=1;
        char ch;

        for(int i=0; i<n; i++)
        {
            getchar();
            for(int j=0; j<m;j++)
                {
                    scanf("%c",&ch);
                    if(ch=='x')
                    {
                        node temp;
                        temp.x=i;
                        temp.y=j;
                        point[0]=temp;
                    }
                    if(ch=='g')
                    {
                        node temp;
                        temp.x=i;
                        temp.y=j;
                        point[N++]=temp;
                    }
                }
        }

        memset(dp,-1,sizeof(dp));

        printf("Case %d: %d\n",cs,solve(0,0));


    }





    return 0;
}

