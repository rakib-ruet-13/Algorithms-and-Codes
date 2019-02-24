#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {
         long long int a,b,c;

         scanf("%lld %lld %lld",&a,&b,&c);

         if(a<b)
            swap(a,b);
         if(a<c)
            swap(a,c);

         printf("Case %d: ",cs);

         //cout<<a<<b<<c<<endl;
         if(a*a==(b*b+c*c))
            printf("yes\n");
         else
            printf("no\n");
    }





    return 0;
}
