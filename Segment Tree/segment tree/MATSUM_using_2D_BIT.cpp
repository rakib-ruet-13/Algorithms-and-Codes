#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pi acos(-1.0000)
#define mp make_pair
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define mem(x,a) memset(x,a,sizeof(a))
#define sz size()
#define scan(a) scanf("%lld",&a);
#define scani(a) scanf("%d",&a);
#define print(a) printf("%lld\n",a);
#define printi(a) printf("%d\n",a);
#define uu first
#define vv second

int max_x,max_y;
int  max_val; /****** The size of array******/

int tree[1034][1034];


/***2D BIT***/

void updatex(int x , int y , int val);
void updatey(int x , int y , int val);
void update_xy(int x , int y , int val);
int readx(int x,int y);
int ready(int x,int y);

void updatex(int x , int y , int val){
    while (x <= max_x){
        updatey(x , y , val);
        // this function should update array tree[x]
        x += (x & -x);
    }
}

void updatey(int x , int y , int val){
    while (y <= max_y){
        tree[x][y] += val;
        y += (y & -y);
    }
}

void update_xy(int x , int y , int val){
    int y1;
    while (x <= max_x){
        y1 = y;
        while (y1 <= max_y){
            tree[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

int readx(int x,int y){
    int sum = 0;
    while ( x > 0){
        sum +=ready(x,y);
        x -= (x & -x);
    }
    return sum;
}

int ready(int x,int y){
    int sum = 0;
    while ( y > 0){
        sum +=tree[x][y];
        y -= (y & -y);
    }
    return sum;
}



int main()
{
     int tc;
    scanf("%d",&tc);

    int row,col;

    while(tc--)
    {
        scani(max_x);
        max_y=max_x;
        max_val=1024;

        row=col=max_x;
        col=row;





        for(int i=0; i<=1024; i++)
            for(int j=0; j<=1024; j++)
            {
                tree[i][j]=0;
            }



        while(1)
        {
            char str[10];
            scanf("%s",&str);

            if(str[1]=='E')
            {
                int x,y,k;
                scani(x);
                scani(y);
                scani(k);

                int p=readx(x+1,y+1)+readx(x,y)-readx(x+1,y)-readx(x,y+1);

                k=k-p;

                update_xy(x+1,y+1,k);
            }
            else if(str[1]=='U')
            {
                int x1,y1,x2,y2;

                scani(x1);
                 scani(y1);
                  scani(x2);
                   scani(y2);

                int res=readx(x2+1,y2+1)+readx(x1,y1)-readx(x2+1,y1)-readx(x1,y2+1);

                printf("%d\n",res);
            }
            else
            {
               // printf("\n");
                break;
            }



            // cout<<str[1]<<endl;

        }

    }







    return 0;
}



