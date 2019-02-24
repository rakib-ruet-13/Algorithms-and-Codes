#include<iostream>
#include<cstring>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    int l1,k,i;
    char st[10001],str[10001],r_str[10001];

    while(gets(st))
    {
        if(!strcmp(st,"DONE"))
            break;
        k=0;
        l1=strlen(st);
        for(i=0;i<l1;i++)
        {
            if(st[i]>='A' && st[i]<='Z')
                    str[k++]=char(st[i]+32);
            if(st[i]>='a' && st[i]<='z')
                str[k++]=st[i];
                //cout<<str[k-1]<<endl;
        }

        for(int j=k-1;j>=0;j--)
        {
            r_str[k-j-1]=str[j];
        }

        int flag=1;
        for(i=0;i<k;i++)
        {
            if(str[i]!=r_str[i])
            {
                flag=0;
                break;
            }
        }

        if(flag==1)
         cout<<"You won't be eaten!"<<endl;
        else
            cout<<"Uh oh.."<<endl;

    }
    return 0;
}

