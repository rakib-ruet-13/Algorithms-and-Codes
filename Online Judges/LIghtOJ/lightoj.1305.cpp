#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int dis(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return abs(x1*(y2-y3)-y1*(x2-x3)+(x2*y3-y2*x3));


}


int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
        int ax,ay,bx,by,cx,cy,dx,dy;

        scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);

        dx=cx-(bx-ax);
        dy=ay+(cy-by);



        int res=dis(ax,ay,bx,by,cx,cy);

        printf("Case %d: %d %d %d\n",cs,dx,dy,res);

    }


    return 0;
}
