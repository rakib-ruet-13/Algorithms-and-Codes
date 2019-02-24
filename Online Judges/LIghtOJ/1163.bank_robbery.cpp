#include<iostream>
#include<bits/stdc++.h>

using namespace std;




int main()
{
    long long n;
    int tc;

    scanf("%d",&tc);

    for(int cs=1;cs<=tc;cs++)
    {
       scanf("%lld",&n);
       printf("Case %d: ",cs);

       if(n%9==0)
       {
           cout<<n+(n/9)-1<<" "<<n+(n/9)<<endl;
       }
       else
       {
           cout<<n+n/9<<endl;
       }




    }
}
