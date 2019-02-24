#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int cs=1 ; cs<=tc ; cs++)
    {

        vector<int>vct;
        int n,p,q;
        scanf("%d %d %d",&n,&p,&q);

        for(int i=1; i<=n ; i++)
        {
            int j;
            scanf("%d",&j);
            vct.push_back(j);
        }
        sort(vct.begin(),vct.end());

        int cnt=0;

        for(int i=0; i<vct.size();i++)
        {
            if(cnt<p && vct[i]<=q)
            {
                cnt++;
                q=q-vct[i];
            }
        }

        printf("Case %d: %d\n",cs,cnt);
        vct.clear();

    }
}
