#include<iostream>
#include<bits/stdc++.h>
#define mod 1000003

using namespace std;

int arr[2][1000010];

void CLEAR()
{
     for(int i=0;i<2; i++)
        for(int j=0;j<1000010;j++)
    {
        arr[i][j]=0;
    }
}


int ncr(int n,int r)
{
    for(int i=0;i<=n;i++)

    {
        for(int j=0;j<=i;j++)
    {
        if(j==0 || j==i)
            arr[i%2][j]=1;
        else
        {
            arr[i%2][j]=(arr[(i+1)%2][j]+arr[(i+1)%2][j-1])%mod;
        }


        if(j==r)
            break;

        //cout<<arr[i%2][j]<<" ";
    }

    //cout<<endl;

    }
    return arr[n%2][r];


}

int main()
{



    int n,r;
    while(cin>>n>>r)
    {
        CLEAR();
        cout<<ncr(n,r)<<endl;

    }






}
