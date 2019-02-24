#include<iostream>
using namespace std;

int main()
{
    int arr[10000];
    int n,i,j,flag1,flag2;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            cin>>arr[i];

    flag2=0;
    for(i=0;i<n;i++)
    {
        for(int k=0;k<n;k++)
        {

        if(k%2==0)
        {
            if(arr[k]==n-1)
              arr[k]=0;
            else
                arr[k]+=1;

        }
        else
        {
            if(arr[k]==0)
                arr[k]=n-1;
            else
                arr[k]=arr[k]-1;
        }
        }

        flag1=0;


        for(j=0;j<n;j++)
        {

            if(arr[j]==j)
            flag2=1;
            else
            {
                flag2=0;
                break;
            }


        }
        if(flag2==1)
           {

            cout<<"Yes"<<endl;
            flag1=1;
            break;
           }
    }
         if(flag1==0)
        cout<<"No"<<endl;

    }

}
