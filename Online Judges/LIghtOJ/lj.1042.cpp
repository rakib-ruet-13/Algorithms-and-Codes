#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int mask;

bool check ( long long n,int pos) { return n&(1<<pos);}
long long Set(long long n,int pos) { return n | (1<<pos);}
long long Reset(long long n,int pos) { return n^(1<<pos);}


int main()
{
    int tc;

    scanf("%d",&tc);




    for(int cs=1; cs<=tc ;cs++)
    {
        long long n;
        scanf("%lld",&n);




        long long res=0;

        int flag=0;

        for(int i=0; i<60;i++)
        {
            if(check(n,i))
                flag=1;
            else
            {
                if(flag)
                {
                    res=Set(n,i);
                    res=Reset(res,i-1);

                    int cnt=0;

                    for(int k=i-2; k>=0 ;k--)
                    {
                        if(check(res,k))
                            {
                                cnt++;
                                res=Reset(res,k);

                            }


                    }

                    for(int p=0; p<cnt;p++)
                    {
                        //cout<<"in"<<endl;
                        res=Set(res,p);
                    }

                    break;
                }
            }
        }


        printf("Case %d: %lld\n",cs,res);
    }

    return 0;
}
