#include<iostream>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>


    int bye[100001],sell[100001];


using namespace std;

int main()
{
    long int n,s,p,d,i,cnt,x;
    char ch;

    cin>>n>>s;

    for(i=0;i<n;i++)
    {
        cin>>ch;
        if(ch=='B')
        {
            cin>>p;
            cin>>d;
            bye[p]+=d;
        }
        else
        {
            cin>>p;
            cin>>d;
            sell[p]+=d;
        }



    }
    cnt=0;
    for(i=0;i<=100000;i++)
    {
        if(sell[i]>0)
        {
            //cout<<"S "<<i<<" "<<sell[i]<<endl;
            cnt++;
            if(cnt==s)
            {
                 x=i;
                 break;
            }

        }
        x=i;
    }

    cnt=0;
     for(i=x;i>=0;i--)
    {
        if(sell[i]>0)
        {
            cout<<"S "<<i<<" "<<sell[i]<<endl;
            cnt++;
            if(cnt==s)
                break;
        }
    }

    cnt=0;
     for(i=100000;i>=0;i--)
    {
        if(bye[i]>0)
        {
            cout<<"B "<<i<<" "<<bye[i]<<endl;
            cnt++;
            if(cnt==s)
                break;
        }
    }







    return 0;
}

