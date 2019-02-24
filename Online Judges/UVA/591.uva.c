#include<stdio.h>
int main()
{
    int tc,i,avg,cnt;
    static int m=1;
    int arr[100];
    while(scanf("%d",&tc)==1 && tc!=0)
    {
        avg=0;
        cnt=0;
        for(i=0;i<tc;i++)
            {
                scanf("%d",&arr[i]);
                avg=avg+arr[i];
            }
            avg=avg/tc;

        for(i=0;i<tc;i++)
        {
            if(arr[i]>avg)
                cnt=cnt+(arr[i]-avg);
        }
        printf("Set #%d\n",m);
        printf("The minimum number of moves is %d.\n\n",cnt);
            m++;
    }
    return 0;
}
