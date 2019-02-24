#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int> >pq;
    vector<int>vct;

    int n;
    long long sum,num;

    while(scanf("%d",&n)==1 && n)
    {
        sum=0;

        for(int i=0;i<n;i++)
        {
            cin>>num;
            pq.push(num);
        }

        while(pq.size()!=1)
        {
              int x=pq.top();
              pq.pop();
              int y=pq.top();
              pq.pop();
              sum+=x+y;
              pq.push(x+y);

        }

        //cout<<sum<<endl;
        while(!pq.empty())
        {
            pq.pop();
        }



        cout<<sum<<endl;


    }
}
