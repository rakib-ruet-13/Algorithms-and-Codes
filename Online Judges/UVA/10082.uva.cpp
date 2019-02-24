#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

using namespace std;

char a[]={"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};

char change(char ch)
{
    for(int i=0;i<47;i++)
    {
        if(a[i]==ch) return a[i-1];
    }
    return ch;
}

int main()
{
    int l,i;
    char str[10005];
    while(gets(str))
    {
        l=strlen(str);
        for(i=0;i<l;i++)
            str[i]=change(str[i]);
        puts(str);
    }
    return 0;
}
