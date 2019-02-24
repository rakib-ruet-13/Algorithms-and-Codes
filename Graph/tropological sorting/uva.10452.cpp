#include<iostream>
#include<bits/stdc++.h>
#define valid(x,y) (x>=1 && x<=row && y>=1 && y<=col)

using namespace std;
string res="IEHOVA#";

char arr[100][100];
int colour[100][100];

int row,col;

int dx[]={0,-1,0};
int dy[]={-1,0,+1};

pair<int,int>st,ed;

void dfs(int x,int y,string str,vector<string>path)
{


    int p,q;

     if(x==ed.first && y==ed.second)
        {
            for(int i=0; i<7 ;i++)
            {
                if(i==0)
                    cout<<path[i];
                else
                    cout<<" "<<path[i];
            }
                    cout<<endl;
                return ;
        }



    for(int i=0; i<=2 ; i++)
    {
        //cout<<"in"<<endl;

        //cout<<"x="<<x<<" y="<<y<<endl;
        p=x+dx[i];
        q=y+dy[i];
        //cout<<"p="<<p<<" q="<<q<<endl;

        if(valid(p,q))
        {


            //cout<<str<<endl;
            //cout<<arr[p][q]<<" " <<res[str.size()]<<p<<q<<x<<y<<endl;
            if(arr[p][q]==res[str.size()])
                {
                    //cout<<"in"<<endl;
                       str+=arr[p][q];
                   // cout<<str<<endl;
                    if(p==x && q==y-1)
                    {
                        path.push_back("left");
                    }
                     else if(p==x && q==y+1)
                     {
                         path.push_back("right");
                     }
                     else
                     {
                         path.push_back("forth");
                     }






                   // for(int i=0;i<path.size(); i++)
                    //{
                     //   cout<<path[i]<<" hfj";
                   // }
                    dfs(p,q,str,path);
                }

        }
    }
}


int main()
{

    int tc;
    scanf("%d",&tc);


    for(int cs=1 ;cs<=tc ;cs++)
    {
        scanf("%d %d",&row,&col);

        for(int i=1;i<=row; i++)
        {
            for(int j=1;j<=col ; j++)
            {
                char ch;
                cin>>ch;

                arr[i][j]=ch;

                if(ch=='@')
                    st=make_pair(i,j);
                if(ch=='#')
                    ed=make_pair(i,j);

            }
        }

        for(int i=0;i<=row; i++)
        {
            for(int j=0;j<=col; j++)
            {
                colour[i][j]=0;
            }
        }


        vector<string>path;
        path.clear();
        dfs(st.first,st.second,"",path);




    }
    return 0;
}
