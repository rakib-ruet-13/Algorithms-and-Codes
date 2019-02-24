#include<iostream>
#include<bits/stdc++.h>

using namespace std;
double prob[101];
int doller[101];
int N;
double dp[101][10101];

double solve(int pos,int take)
{
    if(take<=0)
        return 0;
    if(pos>N)
        return 11;

    if(dp[pos][take]!=11111111.00)
        return dp[pos][take];

    double p1,p2;
    p1=prob[pos]+(1-prob[pos])*solve(pos+1,take-doller[pos]);
    p2=solve(pos+1,take);

    return dp[pos][take]=min(p1,p2);

}

int main()
{
    //freopen("input.txt","r",stdin);

    int tc;

    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ;cs++)
    {
        double p;
        scanf("%lf %d",&p,&N);

        for(int i=1; i<=N; i++)
            scanf("%d %lf",&doller[i],&prob[i]);


        int lo=0;
        int hi=10010;

        int mid=(lo+hi)/2;

       for(int k=0; k<26 ; k++)
        {
            for(int i=0; i<101; i++)
                for(int j=0; j<10100; j++)
                dp[i][j]=11111111.00;

            double x=solve(1,mid);

            if(x-p>=0.00000)
                hi=mid;
            else
                lo=mid;

            mid=(hi+lo)/2;

            if(hi==lo)
                break;

        }

        printf("Case %d: %d\n",cs,mid);



    }



    return 0;
}
