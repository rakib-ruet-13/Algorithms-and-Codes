#include<stdio.h>
#include<math.h>
int main()
{
    long int arr[3000];
    long int i,j,k;
    int check;
    char ch;
    while(1)
    {
        k=0;
       // while(scanf("%d",&j)==1)
       while((ch=getche()) !='\r' )
        {
            scanf("%d",&j);
            arr[k]=j;
            k=k+1;

        }
        for(i=0;i<k-1;k++)
        {
            if(i>0)
            {
                if((abs(arr[i]-arr[i-1])<abs(arr[i]-arr[i+1]))  ||  abs(arr[i]-arr[i+1])<=0 )
                {

                    check=0;
                    break;
                }
                   else
                    {
                        printf("yes\n");
                        check=1;
                    }

            }
        }
        if(check==1)
            printf("jolly\n");
        else
            printf("Not jolly\n");

    }
    return 0;

}
