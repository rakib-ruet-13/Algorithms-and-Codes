#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    long long int tc;

    char arr[10][10];

    int A=1000,B=1000;
    //cin>>tc;

    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
    {
        cin>>arr[i][j];
    }


    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
    {
        if(arr[j][i]=='B')
        {
            int cnt=0;
            for(int k=j+1;k<=8;k++)
            {
                if(arr[k][i]=='W')
                    {
                        cnt=100;
                        break;
                    }
                    else
                        cnt++;
            }

            B=min(B,cnt);


        }


    }


    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
    {
        if(arr[j][i]=='W')
        {
            int cnt=0;
            for(int k=j-1;k>=1;k--)
            {
                if(arr[k][i]=='B')
                    {
                        cnt=100;
                        break;
                    }
                    else
                        cnt++;
            }

            A=min(A,cnt);


        }


    }


    if(A<=B)
        cout<<"A"<<endl;
    else
        cout<<"B"<<endl;


}
