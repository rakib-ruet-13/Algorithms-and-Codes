#include<stdio.h>
int main()
{
    int tc,ll,ul,sum,i,j=1;
    scanf("%d",&tc);
    while(j<=tc)
    {
        sum=0;
        scanf("%d %d",&ll,&ul);
        if(ll%2==0)
            ll=ll+1;
            i=ll;
        while(i<=ul)
        {
            sum=sum+i;
                i=i+2;
        }
        printf("Case %d: %d\n",j,sum);
        j++;


    }
    return 0;
}

