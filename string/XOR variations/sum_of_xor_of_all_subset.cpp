#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int arr[100010];

long long power(int base,int p)
{
    long long res=1;

    for(int i=1; i<=p; i++)
        res*=base;

    return res;
}

long long xor_sum_of_all_subset(int n)
{
    int p=0;

    for(int i=0; i<n; i++)
        p|=arr[i];

    long long a=power(2,n-1);
    a*=p;

    return a;


}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {
        int n;
        scanf("%d",&n);

        for(int i=0; i<n ; i++)
        {
            scanf("%d",&arr[i]);
        }

        printf("Case %d: %lld\n",cs,xor_sum_of_all_subset(n));


    }



    return 0;
}
