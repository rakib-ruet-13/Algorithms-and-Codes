#include<iostream>
#include<bits/stdc++.h>


using namespace std;


int main()
{

    string str;

    long long div;


    int tc;

    scanf("%d",&tc);


    for(int cs=1; cs<=tc; cs++)
    {


        cin>>str;
        scanf("%lld",&div);


        long long num=0;

         bool flag=0;

        for(int i=0;i<str.size();i++)
        {

            num=num*10+str[i]-48;

            if(num>= div)

           {
                printf("%lld",num/div);
                flag=1;

           }
            else if(flag==1)
            printf("0");


            num=num%div;

        }

        if(flag==0)
            printf("0");

        printf(" ");

        printf("%lld\n",num);



    }

    return 0;


}
