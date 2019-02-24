#include<iostream>
using namespace std;

int main()
{
    int arr[10000];
    long int tc,hj,lj,n,i,j;
    cin>>tc;
    for(i=1;i<=tc;i++)
    {
        lj=0;
        hj=0;
        cin>>n;
        for(j=0;j<n;j++)
            cin>>arr[j];
        for(j=0;j<n-1;j++)
        {
            if(arr[j]<arr[j+1])
                hj++;
            if(arr[j]>arr[j+1])
                lj++;
        }
        cout<<"Case "<<i<<": "<<hj<<" "<<lj<<endl;

    }
    return 0;

}
