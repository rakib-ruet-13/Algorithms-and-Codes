#include<iostream>
#include<bits/stdc++.h>


using namespace std;


int main()
{
    int tc;

    scanf("%d",&tc);
    vector<int>vct1;
    vector<int>vct2;

    for(int cs=1;cs<=tc;cs++)
    {
        int p,l,q;

        scanf("%d %d",&p,&l);
        if(p-l<=l)
            printf("Case %d: impossible\n",cs);
        else
        {
            q=p-l;

            for(int i=1;i<=sqrt(q);i++)
            {
                if(q%i==0)
                {
                    vct1.push_back(i);
                    if(i*i!=q)
                    vct2.push_back(q/i);
                }
            }

             printf("Case %d:",cs);
             int l1=vct1.size();
             int l2=vct2.size();


             for(int i=0;i<l1;i++)
                {
                    if(vct1[i]>l)
                    printf(" %d",vct1[i]);
                }
             for(int i=l2-1;i>=0;i--)
             {
                 if(vct2[i]>l)
                 printf(" %d",vct2[i]);

             }

             printf("\n");

        }

        vct1.clear();
        vct2.clear();


    }




}
