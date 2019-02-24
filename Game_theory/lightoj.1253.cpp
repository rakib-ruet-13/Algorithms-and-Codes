#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{

    int tc;
    scanf("%d",& tc);

    for(int cs=1 ; cs<= tc ; cs++)
    {
        int n;
        scanf("%d",&n);

        long long sum=0;

        bool flag=0;

        for(int i=0 ; i<n ;i++)
        {

            int val;
            scanf("%d",&val);

            if(val>1)
                flag=1;

            sum=sum^val;
        }

        if(flag)
        {
        if(sum!=0)
            printf("Case %d: Alice\n",cs);
        else
            printf("Case %d: Bob\n",cs);

        }
        else
        {
             if(n%2==0)
            printf("Case %d: Alice\n",cs);
        else
            printf("Case %d: Bob\n",cs);

        }



    }

    return 0;


}

