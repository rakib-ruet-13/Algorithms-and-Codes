#include<iostream>
#include<bits/stdc++.h>


using namespace std;

struct node
{
    long long x;
    long long y;

    int pos;

    double dis;

}nd[1000010];


bool comp(node a,node b)
{
    return a.dis<b.dis;
}

int main()
{
    int n;

    long long m,p,a,b;

    cin>>n;


    cin>>a>>b;

    //cout<<" ***";

    for(int i=0;i<n-1;i++ )
    {

       // cout<<i<<" "<<n<<endl;
        cin>>m>>p;
        nd[i].x=m;
        nd[i].y=p;

        nd[i].pos=i+2;

        nd[i].dis=sqrt((a-m)*(a-m)+(b-p)*(b-p));

       // cout<<" ***";

    }


    sort(nd,nd+(n-1),comp);

    cout<<1<<" ";
    cout<<nd[0].pos<<" ";


    for(int i=1;i<=n;i++)
    {
        if( ( ((double)nd[0].y-(double)b)/((double)nd[0].x-(double)a) ) != ( ((double)nd[i].y-(double)b)/((double)nd[i].x-(double)a) ) )
        {
            cout<<nd[i].pos<<endl;
            return 0;
        }
    }




}
