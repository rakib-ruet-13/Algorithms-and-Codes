#include<iostream>
#include<bits/stdc++.h>

#define pi acos(-1.0000);
#define rep(x,n) for(int i=x;i<=n;i++)
#define LL long long
#define pb(x) push_back(x)
#define valid(x,y) (x>=0 && x<row && y>=0 && y<col)
#define mem(x,y) memset(x,y,sizeof(x))
#define uu first
#define vv second
#define pii pair<int,int>

using namespace std;

bool comp(int a,int b)
{
    if(a>b)
        return true;
    else
        return false;
}

int main()
{
    int n,m;
    vector<int>f,b,a;


    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        int  a;
        cin>>a;
        b.push_back(a);
    }

    for(int i=0;i<m;i++)
      {
          int a;
          cin>>a;
          f.push_back(a);
      }
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());

    if(n<m)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }

    int cnt=0;
    for(int i=0;i<f.size();i++)
    {
        //double r;

        bool flag=true;

        for(int j=0;j<b.size();j++)
        {

                if(!(f[j]%b[i]==0))
                {
                    flag=false;
                    break;
                }

        }

        if(flag==true)
        {
            cnt++;
            if(cnt<=1)
                for(int k=0;k<m;k++)
            {
                a.push_back(b[k]/f[i]);
            }
            if(cnt>=2)
            {
                cout<<"Ambiguity"<<endl;
                return 0;
            }
        }

    }

    if(cnt==1)
    {
        cout<<"Possible"<<endl;
        for(int i=0;i<m;i++)
        {
            if(i==0)
            cout<<a[i];
            else
            cout<<" "<<a[i];

        }
        cout<<endl;
    }
    else
        cout<<"Impossible"<<endl;





    return 0;
}

