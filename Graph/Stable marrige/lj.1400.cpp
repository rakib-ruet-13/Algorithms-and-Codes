#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int>boys[101];
int mat[101][101];

struct node
{
    bool marrige;
    int partner;
};
int n;

int girl[101];

node stable[101];

void solve()
{
    for(int i=1; i<=n;i++)
      {
          stable[i].marrige=false;
          stable[i].partner=0;
          girl[i]=0;
      }

    bool flag=true;

    while(flag)
    {
        for(int i=1; i<=n ;i++)
        {
            if( stable[i].marrige==false)
            {
                int p=boys[i].back();
                boys[i].pop_back();

                if(girl[p]==0)
                {
                    stable[i].marrige=true;
                    stable[i].partner=p;
                    girl[p]=i;

                }
                else
                {
                    if( mat[p][girl[p]] > mat[p][i])
                    {
                        stable[girl[p]].marrige=false;
                        stable[girl[p]].partner=0;
                        girl[p]=i;

                        stable[i].marrige=true;
                        stable[i].partner=p;

                    }
                }
            }
        }

         flag=false;

        for(int i=1; i<=n ;i++)
        {
            if(!stable[i].marrige)
            {
               flag=true;
               break;
            }
        }



    }
}


int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {

        scanf("%d",&n);


         for(int i=1; i<=n ;i++)
        {
            for(int j=1; j<=n ;j++)
            {
                int pri;
                scanf("%d",&pri);

                mat[i][pri-n]=j;
            }
        }



        for(int i=1; i<=n ;i++)
        {
           for(int j=1; j<=n;j++)
           {
               int pri;
               scanf("%d",&pri);

               boys[i].push_back(pri);
           }
        }

        for(int i=1;i<=n;i++)
        {
            reverse(boys[i].begin(), boys[i].end());
        }


         solve();

      printf("Case %d:",cs);

      for(int i=1;i<=n;i++)
      {
          printf(" (%d %d)",i,girl[i]+n);

      }

      printf("\n");

      for(int i=0;i<=n;i++)
      {
          boys[i].clear();
      }




    }
}
