#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    queue<int>q;

    int n;
    while(cin>>n && n)
    {
        for(int i=1;i<=n;i++)
            q.push(i);

        bool flag=false;

        cout<<"Discarded cards:";

        while(q.size()!=1)
        {
            if(!flag)
            {
                cout<<" "<<q.front();
                flag=true;
            }
            else
            {
                cout<<", "<<q.front();
            }
            q.pop();
            int val=q.front();
            q.pop();
            q.push(val);

        }

            printf("\nRemaining card: %d\n",q.front());
            q.pop();



    }
}
