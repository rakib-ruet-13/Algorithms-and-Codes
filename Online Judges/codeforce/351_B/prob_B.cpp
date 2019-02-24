#include<iostream>
#include<bits/stdc++.h>

using namespace std;



int arr1[5000000];
int arr2[5000000];

int main()
{
    long long n,m;

    scanf("%lld %lld",&n,&m);


    memset(arr1,0,sizeof(arr1));
      memset(arr2,0,sizeof(arr2));


    for(int i=0;i<m ;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);

        if(a>b)
            swap(a,b);

        arr1[a]++;

        arr2[b]++;


    }



    int mx,mn;

    for(int i=1; i<=n ; i++)
    {
        if(arr1[i]!=0)
            mx=i;

    }

     for(int i=1; i<=n ; i++)
    {
        if(arr2[i]!=0)
          {
              mn=i;
              break;
          }

    }

    int res;

    if(m==0)
    {
        printf("%d\n",n-1);
        return 0;

    }

    if(mx>=mn)
        res=0;

    else
        res=1+(mn-mx-1);


    printf("%d\n",res);


    return 0;


}

