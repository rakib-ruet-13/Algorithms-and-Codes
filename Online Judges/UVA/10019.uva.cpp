#include<iostream>
#include<cstring>
using namespace std;



int binary_sum(int num)
{
    int sum;
    sum=0;

    do
    {
        sum+=num%2;
        num=num/2;
    }
    while(num!=0);

        return sum;
}

 int power(int base,int p)
{
    int ans;

    if(p==0)
        return 1;

    ans=1;
    for(int i=1;i<=p;i++)
        ans=ans*base;

        return ans;
}

int convert_hex(int num)
{
    int sum=0;
    int i=0;
    do
    {
        sum=sum+(num%10)*power(16,i);
        i++;
        num=num/10;
    }
    while(num!=0);

    return sum;
}

int main()
{
    int num,hex_num,tc;
    cin>>tc;
    while(tc--)
    {
        cin>>num;
        hex_num=convert_hex(num);

        cout<<binary_sum(num)<<" "<<binary_sum(hex_num)<<endl;
    }



}
