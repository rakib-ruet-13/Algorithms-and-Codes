#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {
        int n;
        scanf("%d",&n);

        double N;
        N=n;


        double res=0;
        for(int i=1; i<=n; i++)
        {
            res+=N/(double)i;
        }

       printf("Case %d: %.10f\n",cs,res);


    }




    return 0;
}
