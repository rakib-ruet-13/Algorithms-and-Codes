#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int main()
{

    int tc;
    scanf("%d",&tc);


    for(int cs=1 ; cs<= tc ;cs++)
    {
        int a,b;

        scanf("%d %d",&a,&b);

        printf("Case %d: %d\n",cs, (a+abs(b-a))*4+10+9);
    }


}
