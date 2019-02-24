#include<iostream>
#include<bits/stdc++.h>

using namespace std;



int main()
{
    int tc;
    scanf("%d",&tc);

    vector<long long>vct;

    for(int cs=1; cs<=tc; cs++)
    {
        int n,q;
        scanf("%d %d",&n,&q);


        for(int i=0; i<n ;i++)
        {
            int a;
            scanf("%d",&a);
            vct.push_back(a);
        }

        while(q--)
        {
            char ch;
            cin>>ch;

            if(ch=='S')
            {
                int d;
                scanf("%d",&d);

                for(int i=0 ; i<n ;i++)
                {
                    vct[i]+=d;
                }

            }
            else if(ch=='M')
            {
                int d;
                scanf("%d",&d);

                for(int i=0 ; i<n ;i++)
                {
                    vct[i]*=d;
                }

            }
            else if(ch=='D')
            {
                int d;
                scanf("%d",&d);

                for(int i=0 ; i<n ;i++)
                {
                    vct[i]/=d;
                }

            }
            else if(ch=='R')
            {
                reverse(vct.begin(),vct.end());
            }
            else
            {
                int p,q;
                scanf("%d %d",&p,&q);

                swap(vct[p],vct[q]);
            }
        }


        printf("Case %d:\n",cs);

        for(int i=0; i<n ;i++)
        {
            if(i==0)
             printf("%lld",vct[i]);
            else
            printf(" %lld",vct[i]);
        }
        printf("\n");

        vct.clear();

    }





}
