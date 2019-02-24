#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int temp,i,j,k,a[100000],tc,cnt,n;
    scanf("%d",&tc);
    while(tc--)
    {
        cnt=0;
        scanf("%d",&n);
        for(int k=0;k<n;k++)
            scanf("%d",&a[k]);

        for(i=0;i<n-1;i++)
            for(j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            cnt++;
        }

        printf("Optimal train swapping takes %d swaps.\n",cnt);
    }
    return 0;
}
