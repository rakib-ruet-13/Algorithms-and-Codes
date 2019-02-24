#include<stdio.h>
#include<string.h>
int main()
{
    char str[100000];
    long i,j=0;
    while(gets(str))
    {
        for(i=0;i<strlen(str);i++)
        {
            if(str[i]=='"')
            {
                j=j+1;
                if(j%2==1)
                printf("``");
                else
                printf("''");
            }
            else
            printf("%c",str[i]);
        }
        printf("\n");

    }
    return 0;
}
