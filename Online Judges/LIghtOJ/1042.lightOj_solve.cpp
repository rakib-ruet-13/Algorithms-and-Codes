#include<iostream>
#include<cstdio>
using namespace std;



int count(long long num)
{
    int cnt = 0;

    for(long long t=1; t<= num; t *= 2)
    {
        if((num & (t)) != 0)
        {
            cnt++;
        }
    }
    return cnt;
}



long long int next(long long int num)
{
    long long res;
    for(long long t = 1; t<= num; t *= 2)
    {
        if( (num & (t)) != 0)
        {
            res = num + t;
            break;
        }
    }

    int diff =  count(num) - count(res) ;

    for(int i=0; i<diff; i++)
    {
        res += (1<<i);
    }
    return res;




}


int main()
{
    int kases, kaseno = 0;
    long long int num;

    scanf("%d", &kases);
    while(kases--)
    {
        scanf("%lld", &num);
        num  = next(num);
        printf("Case %d: %lld\n", ++kaseno, num);
    }
    return 0;

}
