#include<iostream>
#include<bits/stdc++.h>

using namespace std;


struct compare
{

    bool operator()(const int& i,const int& j)
    {
        return i<j;
    }

};


struct node
{
    long long int u,cost;
    node(int x,int y)
    {
        u=x;
        cost=y;

    }

    bool operator > (const node& temp) const
    {
        return cost>temp.cost;
    }

};

int main()
{

    priority_queue<int,vector<int>,greater<int> >pri_q;
    priority_queue<node,vector<node>,greater<node> >pq;

    for(int i=0;i<10;i++)
    {
        pri_q.push(10+(i%2+i));
        pq.push(node(10+i,10+i));
    }

    while(!pri_q.empty())
    {
        cout<<pri_q.top()<<endl;
        pri_q.pop();
    }

    while(!pq.empty())
    {
        cout<<pq.top().u<<" "<<pq.top().cost<<endl;
        pq.pop();
    }


}
