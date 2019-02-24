#include<iostream>
#include<stdio.h>
#define MAX 10000
using namespace std;
void Gen_prime(void);
bool sieve[MAX];
void Gen_prime(void)
{

    unsigned long long int num;

    static unsigned long long int i,j;
    for(i=4;i<=MAX;i+=2)
        sieve[i]=1;
    for(i=3;i*i<=MAX;i+=2)
    {
        if(sieve[i]==0)
            for(j=i*i;j<=MAX;j=2*i+j)
            sieve[j]=1;
    }
}
int main()
{
    int cnt,n,c;
    int arr[10000];
    Gen_prime();
    while(scanf("%d %d",&n,&c)==2)
    {
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(sieve[i]==0)
                arr[++cnt]=i;
        }
        printf("%d %d:",n,c);

        if(cnt<=2*c-1)
            for(int i=1;i<=cnt;i++)
            printf(" %d",arr[i]);
        else if(cnt%2==0)
            for(int i=(cnt/2)-(c-1);i<=(cnt/2)+c;i++)
            printf(" %d",arr[i]);
        else
            for(int i=((cnt/2)+1)-(c-1);i<=((cnt/2)+c);i++)
            printf(" %d",arr[i]);

            printf("\n\n");

    }
    return 0;
}
