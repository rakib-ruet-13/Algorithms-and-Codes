#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int Mat[1001][1001];

int main()
{
    long long int Node,Edge,n1,n2,Cost;

    cin>>Node>>Edge;

    for(int i=0;i<Edge;i++)
    {
        cin>>n1>>n2>>Cost;
        /****Bi directed ****/
        Mat[n1][n2]=Cost;
        Mat[n2][n1]=Cost;
    }

}
