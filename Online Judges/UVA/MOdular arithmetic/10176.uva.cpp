#include<iostream>
#include<bits/stdc++.h>

using namespace std;


long long int mod(long long int n,long long int p,long long int m)
{
    if(p==0)
        return 1;
    else if(p%2==0)
    {
        long long int res=mod(n,p/2,m);
        return (res%m)*(res%m);

    }
    else
        return (n%m)*(mod(n,p-1,m)%m);
}


int main()
{
    char str[10000];
    while(cin>>str[0])
    {
        char ch;
        int k=1;

        while(cin>>ch && ch!='#')
            {
               str[k++]=ch;

            }
        str[k]='\0';

        int l=strlen(str);

        int ans=0;

      //  cout<<l<<endl;

        for(int i=0;i<l;i++)
        {

            if(str[i]=='1')
                ans=ans%131071+mod(2,l-i-1,131071)%131071;


                ans=ans%131071;
                //cout<<ans<<endl;

        }

        if(ans==0)
            printf("YES\n");
        else
            printf("NO\n");


    }

    return 0;
}
