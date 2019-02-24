
#include<stdio.h>
int main()
{
    long int x,y;
    int cnt,c;

    while(scanf("%ld %ld",&x,&y)==2  && (x||y))
    {
        cnt=0;
        c=0;
        while((x||y))
       {      c=((x%10)+(y%10)+c)/10;
            cnt+=c;
            x=x/10;
            y=y/10;
        }
    if(cnt==0)
        printf("No carry operation.\n");
    if(cnt==1)
        printf("%d carry operation.\n",cnt);
    if(cnt>1)
    printf("%d carry operations.\n",cnt);
    }
  return 0;
}
