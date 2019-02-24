#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    vector<int>graph[1000];

    int node,edge,n1,n2;
    cin>>node>>edge;

    for(int i=1;i<=node;i++)
    {
         cin>>n1>>n2;
         graph[n1].push_back(n2);
         graph[n2].push_back(n1);
    }



}
