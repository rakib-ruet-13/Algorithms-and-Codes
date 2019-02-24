#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{

    char arr[101][101];
    int arr1[101][101];

    int n,m,cs=0;
    while(cin>>n>>m && (n!=0 || m!=0))
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            cin>>arr[i][j];

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                arr1[i][j]=0;



        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]=='*')

                {
                    arr1[i][j]=-100000;

                    if(j!=0)
                    arr1[i][j-1]++;

                    if(j!=m-1)
                        arr1[i][j+1]++;

                    if(i!=0)
                        arr1[i-1][j]++;

                    if(i!=n-1)
                        arr1[i+1][j]++;

                    if(i!=0 && j!=0)
                        arr1[i-1][j-1]++;

                    if(i!=n-1 && j!=0)
                        arr1[i+1][j-1]++;
                    if(i!=0 && j!=m-1)
                        arr1[i-1][j+1]++;
                    if(i!=n-1 && j!=m-1)
                        arr1[i+1][j+1]++;
                }
            }
            if(cs!=0)
            printf("\n");

            cout<<"Field #"<<++cs<<":\n";


        for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(arr1[i][j]<0)
                        cout<<"*";
                    else
                       cout<<arr1[i][j];
                }
                printf("\n");
            }

    }
    return 0;
}
