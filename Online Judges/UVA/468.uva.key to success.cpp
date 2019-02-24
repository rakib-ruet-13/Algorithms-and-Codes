#include<iostream>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int main()
{
    char str1[10000];
    char str[10000];
    int i,j,tc;
    cin>>tc;
    gets(str1);
    while(tc!=0)
    {
        gets(str1);
        gets(str);
        for(i=0;i<strlen(str);i++)
        {
            if((str[i]<='W' && str[i]>='A')  ||  (str[i]<='w' && str[i]>='a'))
            str[i]=str[i]+3;
            if((str[i]<='Z' && str[i]>'W')  ||  (str[i]<='z' && str[i]>'w'))
                str[i]=str[i]-23;

        }
        puts(str);
        cout<<"\n";
        tc--;

    }

}
