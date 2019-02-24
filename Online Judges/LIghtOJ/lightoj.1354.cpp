#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long power(long long base,long long p)
{
    long long res=1;

    for(int i=1; i<=p ;i++)
    {
        res*=base;
    }
    return res;
}


long long dec(long long n)
{
    long long  res=0;
    long long cnt=0;
    while(n)
    {
        int dig=n%10;

        res+=dig*power(2,cnt++);
        n=n/10;
    }

    return res;


}
int main()
{

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc ;cs++)
    {
        long long a,b,c,d,e,f,g,h;

        scanf("%lld.%lld.%lld.%lld",&a,&b,&c,&d);
         scanf("%lld.%lld.%lld.%lld",&e,&f,&g,&h);



    e=dec(e);
    f=dec(f);
    g=dec(g);
    h=dec(h);


        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        printf("Case %d: ",cs);

        if(a==e && b==f && c==g && d==h)
            printf("Yes\n");
        else
            printf("No\n");
    }


    return 0;



}
