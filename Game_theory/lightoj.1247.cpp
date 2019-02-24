#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
        int k,col;

        scanf("%d %d",&k,&col);

        int sum=0;
        while(k--)
        {
            int p=0;

            for(int i=0 ;i<col ;i++)
            {
                int val;

                scanf("%d",&val);
                p+=val;
            }

            sum=sum^p;
        }

        if(sum==0)
            printf("Case %d: Bob\n",cs);
        else
            printf("Case %d: Alice\n",cs);
    }

    return 0;
}

