#include<iostream>
#include<bits/stdc++.h>

using namespace std;


long long fact[20];


int main()
{

       fact[0]=1;

    for(int i=1; i<=20; i++)
    {
       fact[i]=fact[i-1]*i;
       //cout<<fact[i]<<" "<<fact[i]%1000000000000000000<<endl;
    }

    int tc;
    scanf("%d",&tc);
    vector<int>vct;



    long long n;

    for(int cs=1; cs<=tc ;cs++)
    {
        scanf("%lld",&n);

          //  cout<<"ok"<<endl;

        if(n==2)
        {
            printf("Case %d: 0!+1!\n",cs);
            continue;
        }


         long long p;

         for(p=20 ; p >=0 ;p--)
         {
             if( n >= fact[p] )
                {
                   // if(n==fact[p] && vct.size()==0)
                       // continue;

                    n-=fact[p];
                    vct.push_back(p);

                }
         }

       // cout<<"ok"<<endl;

           printf("Case %d:",cs);

     if(n==0)
    {
        reverse(vct.begin(),vct.end());

        for(p=0 ; p<vct.size() ;p++)
        {
            if(p==0)
                printf(" %d!",vct[p]);
            else
                printf("+%d!",vct[p]);
        }
    }
    else
    {
         printf(" impossible");
    }


    printf("\n");
    vct.clear();
    }



    return 0;
}
