#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int arr[100010];


long long xor_of_xor_off_al_subset(int n)
{
    if(n==1)
        return arr[0];
    else
        return 0;
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

        printf("Case %d: %lld\n",cs,xor_of_xor_off_al_subset(n));


    }



    return 0;
}

