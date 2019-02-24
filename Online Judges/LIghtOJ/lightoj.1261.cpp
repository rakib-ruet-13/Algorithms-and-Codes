#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int arr[101];

int main()
{

    int tc;
    scanf("%d",&tc);

    vector<int>vct[101];

    for(int cs=1 ; cs<= tc ;cs++)
    {
        int n,p,k;
        scanf("%d %d %d",&n,&p,&k);

        memset(arr,0,sizeof(arr));

        for(int i=1; i<=n ; i++)
        {
           for(int j=1; j<=k ;j++)
           {
               int temp;
               scanf("%d",&temp);
               vct[i].push_back(temp);
           }

        }

        int flag=1;


        int f;
        scanf("%d",&f);

        for(int i=1; i<=f; i++)
        {
            int tmp;
            scanf("%d",&tmp);

            arr[tmp]=1;
        }


        for(int i=1; i<=n; i++)
        {
            int sum=0;

            for(int t=0; t<vct[i].size() ; t++ )
            {
                //cout<<vct[i][t]<<"  "<<arr[vct[i][t]]<<endl;
                if(vct[i][t]>0)
                {
                    if(arr[vct[i][t]]==1)
                         sum++;
                }
                else
                {
                    if(arr[-vct[i][t]]==0)
                         sum++;
                }
            }
            if(sum==0)
            {
                flag=0;
                break;
            }

        }

        printf("Case %d: ",cs);

        if(flag)
            printf("Yes\n");
        else
            printf("No\n");

        for(int i=0; i<100; i++)
            vct[i].clear();
    }
    return 0;
}
