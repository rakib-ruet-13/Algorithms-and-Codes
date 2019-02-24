#include<iostream>
#include<bits/stdc++.h>

using namespace std;
map<char,int >vct;
char grid[111][111];

int x,y;
string str;

int solve()
{

    int cx=x;
    int cy=y;

    for(int i=0; i<str.size(); i++)
    {
        //cout<<str[i];

        int dir=vct[str[i]];

        //cout<<vct[i]<<" == "<<dir <<endl;

        if(dir==0)
        {
            cx++;
            cy;
        }
         if(dir==1)
        {
            cx;
            cy++;
        }
         if(dir==2)
        {
            cx--;
            cy;
        }
         if(dir==3)
        {
            cx;
            cy--;
        }
        //cout<<grid[cx][cy];

        if(grid[cx][cy]=='E')
        {
            vct.clear();
            return 1;

        }

        if(grid[cx][cy]=='#')
            {
                vct.clear();
                return 0;
            }

    }

    vct.clear();
    return 0;

}

int main()
{

//freopen("inp.txt","r",stdin);

    int r,c;
    cin>>r>>c;



     for(int i=0; i<=r+1; i++)
        for(int j=0; j<=c+1;j++)
    {
        grid[i][j]='#';
    }


    for(int i=1; i<=r; i++)
        for(int j=1; j<=c;j++)
    {
        cin>>grid[i][j];
        if(grid[i][j]=='S')
        {x=i;
        y=j;}



    }
    //cout<<"ok"<<endl;

    cin>>str;

    //cout<<str<<endl;

    int cnt=0;

    for(int i=0; i<=3; i++)
    {

        for(int j=0; j<=3;j++)
        {
           if(i==j)
            continue;

           for(int k=0; k<=3; k++)
           {

                if(k==j || k==i)
                    continue;

                     for(int l=0;l<=3; l++)
            {
                if(l!=i && l!=j && l!=k)
                {

                   // cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;



                //cout<<(char)(i+48)<<"  ======== "<<endl;
                vct[(char)(i+48)]=0;
                vct[(char)(j+48)]=1;
                vct[(char)(k+48)]=2;
                vct[(char)(l+48)]=3;

                cnt+=solve();

                }
            }
            }
        }



    }
   //cout<<"ok"<<endl;
    cout<<cnt<<endl;
 return 0;





}
