#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long int x,y;
    int cnt=0;

    while(scanf("%ld %ld",&x,&y)==2  && (x!=0 && y!=0))
    {
        while(!(x||y))
       {if(x%10+y%10>=10)
            cnt++;
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

}
