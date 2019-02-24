#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc ; cs++)
    {
        int n;
        scanf("%d",&n);

        int div=n;
        int sum=0;

        for(int i=0; i<n ; i++)
        {
            int p;
            scanf("%d",&p);
            if(p<1)
                {
                    sum-=p;
                    div--;
                }
            else
            {
                sum+=p;
            }
        }

        printf("Case %d: ",cs);

        if(div==0)
            printf("inf\n");
        else
        {
            int gcd=__gcd(sum,div);
            printf("%d/%d\n", sum/gcd, div/gcd);
        }


    }


  return 0;

}
