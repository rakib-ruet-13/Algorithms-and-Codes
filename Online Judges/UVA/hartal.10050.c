#include<stdio.h>
int main()
{
    int  tn,n;

    while(scanf("%d",&tn)==1)

    for(n=0;n<tn;n++)
    {
    int i,j=0,k,d,np,sum;
    scanf("%d %d",&d,&np);
    sum=0;
    int h[np], arr[d],temp,x=0;
    for(i=0;i<np;i++)
    {
        scanf("%d",&h[i]);
        j=h[i];
        while(j<=d)
        {
            if(j%7!=0 && j%7!=6)
           {
            arr[x]=j;
            x++;
           }
            j=j+h[i];
        }
    }
    for(i=0;i<x-1;i++)
        for(j=0;j<x-1-i;j++)
        {
            if (arr[j]<arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        for(i=0;i<x;i++)
            if(arr[i]==arr[i+1])
                         sum++;

      printf("%d\n",x-sum);
    }

    return 0;
}
