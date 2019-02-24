#include<iostream>
#include<bits/stdc++.h>

using namespace std;



int main()
{
    int tc;

    scanf("%d",&tc);

    int r1,c1,r2,c2;

    for(int cs=1 ;cs<=tc ;cs++)
    {
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);

        bool flag=0;


        if((r1%2==1 && c1%2==1) || (r1%2==0 && c1%2==0))
        {
            if( (r2%2==1 && c2%2==1) || (r2%2==0 && c2%2==0) )
                flag=1;
        }
        else
        {
            if( !((r2%2==1 && c2%2==1) || (r2%2==0 && c2%2==0)) )
                flag=1;
        }



        if(flag==0)
            printf("Case %d: impossible\n",cs);
        else
        {
            if( abs(r1-r2)==abs(c1-c2) )
                printf("Case %d: 1\n",cs);
            else
                printf("Case %d: 2\n",cs);

        }
    }


    return 0;
}
