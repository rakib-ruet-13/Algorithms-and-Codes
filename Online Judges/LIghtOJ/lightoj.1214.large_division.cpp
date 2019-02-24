#include<iostream>
#include<bits/stdc++.h>


using namespace std;


int main()
{

    string str;
    long long div;

    int tc;

    scanf("%d",&tc);


    for(int cs=1; cs<=tc;cs++)
    {


        cin>>str;

        scanf("%lld",&div);

        div=abs(div);

        long long num=0;

        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='-')
                continue;
            num=num*10+str[i]-48;

            num=num%div;

        }

        if(num==0)
        {
            printf("Case %d: divisible\n",cs);
        }
        else
        {
             printf("Case %d: not divisible\n",cs);
        }



    }


}
