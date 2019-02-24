#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
        int k;

        scanf("%d",&k);

        int sum=0;
        while(k--)
        {
            int a,b;
            scanf("%d %d",&a,&b);

            int p=abs(b-(a+1));

            sum=sum^p;
        }

        if(sum==0)
            printf("Case %d: Bob\n",cs);
        else
            printf("Case %d: Alice\n",cs);
    }

    return 0;
}
