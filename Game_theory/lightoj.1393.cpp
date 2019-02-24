#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc ; cs++)
    {
        int row,col;

        scanf("%d %d",&row,&col);


        bool flag=0;
        long long int sum=0;
        long long int ones=0;
        long long s1=0;

        for(int i=1 ; i<= row ;i++)
        {
            long long s1=0;

            for(int j=1 ; j<=col ;j++)
            {
                int val;


                scanf("%d",&val);
                s1+=val;



            }

            if(s1>1)
                flag=1;

            sum^=s1;
        }

        printf("Case %d: ",cs);

        if(flag)
        {
            if(sum!=0)
                printf("win\n");
            else
                printf("lose\n");
        }
        else
        {
            if(ones%2==0)
                printf("lose\n");
            else
                printf("win\n");

        }


    }


}
