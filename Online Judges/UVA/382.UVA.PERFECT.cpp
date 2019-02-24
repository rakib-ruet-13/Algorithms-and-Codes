#include<iostream>
#include<stdio.h>
using namespace std;

void Gen_perfect(long long int num)
{
    long long int i,j,sum;
        sum=0;

        for(j=1;j<=num/2;j++)
    {
        if(num%j==0)
            sum=sum+j;
    }

    if(sum==num)
        printf("%5d  PERFECT\n",num);
    else if(sum<num)
        printf("%5d  DEFICIENT\n",num);
    else
         printf("%5d  ABUNDANT\n",num);





}
int main()
{
    int input[60001];
    int cnt=1;
    while(1)
    {
        cin>>input[cnt];
        if(input[cnt]==0)
            break;
        cnt++;


    }
    cout<<"PERFECTION OUTPUT"<<endl;
    for(int i=1;i<cnt;i++)
    {
        Gen_perfect(input[i]);
    }
    cout<<"END OF OUTPUT\n";

}
