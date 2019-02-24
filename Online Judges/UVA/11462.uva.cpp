#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int arr[2000010];

int main()
{

    int n;

    while(scanf("%d",&n)==1 and n!=0)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        sort(arr,arr+n);

        printf("%d",arr[0]);
        for(int i=1;i<n;i++)
            printf(" %d",arr[i]);
        printf("\n");
    }
}
