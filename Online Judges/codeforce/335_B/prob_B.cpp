#include<iostream>
#include<bits/stdc++.h>

#define valid (x>=1 && x<=n && y<=m && y>=1)

using namespace std;


int main()
{

    int arr[600][600];
    int n,m,x,y;

    cin>>n>>m>>x>>y;

    string str;
    getchar();
    getline(cin,str);

    int cnt=1;

    cout<<1<<" ";
    for(int i=0;i<str.size()-1;i++)
    {
        if(str[i]=='U')
        {
            y++;
            if(valid)
            {
                if(!arr[x][y])
                {
                    cout<<1<<" ";
                    arr[x][y]=1;
                     cnt++;
                }
                else
                    cout<<0<<" ";


            }
            else
                {
                    y--;
                    cout<<0<<" ";
                }
        }

         if(str[i]=='D')
        {
            y--;
            if(valid)
            {
                if(!arr[x][y])
                {
                    cout<<1<<" ";
                    arr[x][y]=1;
                       cnt++;
                }
                else
                    cout<<0<<" ";


            }
            else
               {
                    y++;
                     cout<<0<<" ";

               }
        }


         if(str[i]=='L')
        {
            x--;
            if(valid)
            {
                if(!arr[x][y])
                {
                    cout<<1<<" ";
                    arr[x][y]=1;
                     cnt++;
                }
                else
                    cout<<0<<" ";


            }
            else
                {
                    x++;
                     cout<<0<<" ";
                }
        }


         if(str[i]=='R')
        {
            x++;
            if(valid)
            {
                if(!arr[x][y])
                {
                    cout<<1<<" ";
                    arr[x][y]=1;
                        cnt++;
                }
                else
                    cout<<0<<" ";


            }
            else
              {

              x--;
               cout<<0<<" ";
              }
        }

    }
      cout<<n*m-cnt<<endl;
}
