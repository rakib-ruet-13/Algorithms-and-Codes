#include<iostream>
#include<bits/stdc++.h>
#define Max 100100

using namespace std;





int main()
{
    int tc;
    long long n;

    scanf("%d",&tc);

    for(int cs=1; cs<=tc; cs++)
    {
        scanf("%lld",&n);
        bool f=0;

        if(n<0)
              f=1;

        n=abs(n);

        int i=2;
        bool flag=1;

        while(i<=sqrt(n))
        {
            long long k=n;

            int cnt=0;

            while(k%i==0)
            {
                k=k/i;
                cnt++;
            }

            if(k==1)
            {
                while(f==1 && cnt%2==0)
                   {
                       cnt=cnt/2;
                   }

                printf("Case %d: %d\n",cs,cnt);
                flag=0;
                break;
            }

            i++;
        }

        if(flag==1)
        {
             printf("Case %d: %d\n",cs,1);
        }




    }

}
