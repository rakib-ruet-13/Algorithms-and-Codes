#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int main()
{

    string str,str1;


    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc ;cs++)
    {
        cin>>str;

        bool flag=1;

        for(int i=0 ;i< str.size() ;i++)
        {
            if(str[i]=='A' || str[i]=='H' || str[i]=='I' || str[i]=='M' || str[i]=='O' || str[i]=='T' || str[i]=='U' || str[i]=='V' || str[i]=='W' || str[i]=='X' || str[i]=='Y');
            else
            {
                flag=0;
                break;
            }

        }
        if(flag==0)
        {
            printf("Case %d: usual word\n",cs);
        }
        else
        {
            str1=str;
            reverse(str1.begin(),str1.end());

            if(str1==str)
             printf("Case %d: SameSymWord\n",cs);
            else
                 printf("Case %d: SymWord\n",cs);

        }
    }


    return 0;


}
