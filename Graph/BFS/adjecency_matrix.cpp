#include<iostream>
#include<bits/stdc++.h>

long int Mat[1000][1000];

using namespace std;

int main()
{


    int node,edge,n1,n2,cost;
    cin>>node>>edge;

    for (int i=1;i<=edge;i++)
    {
        cin>>n1>>n2>>cost;
        Mat[n1][n2]=Mat[n2][n1]=cost;

    }

    for(int i=1;i<=node;i++)
    {
        cout<<"Adjecent node of "<<i<<" is=";
        for(int j=1;j<=node;j++)
        {
            if(Mat[i][j]!=0)
                cout<<j<<" ";
        }

        cout<<endl;
    }

    return 0;







}
