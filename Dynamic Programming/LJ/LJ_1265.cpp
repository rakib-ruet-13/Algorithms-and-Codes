#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double ncr(int n,int r)
{
    double res;
    res=n*(n-1)/2;

    return res;
}


int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ; cs++)
    {
        int t,d;
        scanf("%d %d",&t,&d);

        if(t%2==1)
        {
            printf("Case %d: 0.000000000\n",cs);
        }
        else
        {
            double res=1;

            for(int i=t ; i>=2 ; i-=2)
            {
                res*=ncr(i,2)/ncr(i+1,2);
            }

            printf("Case %d: %.10f\n",cs,res);


        }


    }


    return 0;
}
