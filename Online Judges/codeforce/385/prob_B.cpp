#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n,m;

    scanf("%d %d",&n,&m);;
    getchar();

    char ch;

    int cnt=0;


    for(int i=0; i<n*m;i++)
    {
        scanf("%c",&ch);


        if(ch!='.')
            cnt++;
    }


    bool flag=0;

    for(int i=1; i<=n ;i++)
        for(int j=1; j<=m ;j++)
    {

        if(i*j==cnt)
            flag=1;

    }

    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;







    return 0;
}
