
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int arr[110][110];
struct node
{
    int x,y;
};

map<int,node>mymap;

int main()
{

    int tc;
    scanf("%d",&tc);



    for(int cs=1; cs<=tc; cs++)
    {
        int n,m,c;
        scanf("%d %d %d",&n,&m,&c);

        int cnt=1;

        for(int i=1; i<=m; i++)
        {
            if(i%2==1)
            {
                for(int j=1; j<=n;j++)
                {
                   node temp;
                   temp.y=i;
                   temp.x=j;
                   mymap[cnt++]=temp;
                }
            }
            else
            {
                 for(int j=n; j>=1;j--)
                {
                   node temp;
                   temp.y=i;
                   temp.x=j;
                   mymap[cnt++]=temp;
                }

            }
        }

       cnt=1;
       for(int p=1; p<=c; p++)
       {
           int d; scanf("%d",&d);

           while(d--)
           {
               int x=mymap[cnt].x;
               int y=mymap[cnt].y;
               cnt++;

               arr[x][y]=p;
           }



       }

       for(int i=1; i<=n; i++)
       {
        for(int j=1; j<=m; j++)
        {
            if(j!=1)
                printf(" %d",arr[i][j]);
            else
             printf("%d",arr[i][j]);

        }
        printf("\n");
       }

       mymap.clear();
    }


    return 0;
}

