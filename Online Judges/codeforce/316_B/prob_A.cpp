#include<iostream>
using namespace std;

int main()
{

    long long int arr[101][101],n,m,ans[1001],mx,cnt,i,j,k;

    while(cin>>n>>m)
    {

        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }


        for(i=0;i<m;i++)
        {
          mx=0;
          cnt=0;
            for(j=0;j<n;j++)
        {
           if(arr[i][j]>mx)
           {
               mx=arr[i][j];
               cnt=j;
           }
        }

        ans[cnt]++;

        }


        mx=0;
        cnt=0;
        for(i=0;i<n;i++)
        {
            if(ans[i]>mx)
            {
                mx=ans[i];
                cnt=i;
            }
        }
        cout<<cnt+1<<endl;
    }

}
