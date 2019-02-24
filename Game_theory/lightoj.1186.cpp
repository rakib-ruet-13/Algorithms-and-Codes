#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int a[1000001];
int b[1000001];

int main()
{

    int tc;
    scanf("%d",& tc);

    for(int cs=1 ; cs<= tc ; cs++)
    {
        int n;
        scanf("%d",&n);

        long long sum=0;

        for(int i=0 ; i<n ;i++)
        {
            scanf("%d",&a[i]);
        }
         for(int i=0 ; i<n ;i++)
        {
            scanf("%d",&b[i]);

            sum=sum^(b[i]-a[i]-1);
        }

        if(sum==0)
            printf("Case %d: black wins\n",cs);
        else
            printf("Case %d: white wins\n",cs);



    }

    return 0;


}
