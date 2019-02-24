#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Max 100000010

vector<int>vct;

unsigned int status[Max/32+2];

void Set(int n, int pos) { status[n>>5]=(status[n>>5] | (int)1<<pos); }
int check(int n,int pos) { return (status[n>>5] & (int)1<<pos); }

void sieve()
{
    for(int i=4;i<Max;i+=2)
    {

         Set(i,i&31);

         //cout<<i<<endl;
    }

      //cout<<"ok"<<endl;
    int s=sqrt(Max);
    for(int i=3;i<=s; i++)
    {
        if(!check(i,i&31))
        {
            for(int j=i*i,k=i<<1 ; j<=Max; j+=k)
            {
                Set(j, j&31);
            }
        }
    }


   /* for(int i=2; i<=Max;i++)
    {
        if(!check(i,i&31))
        {
            vct.push_back(i);
        }
   }*/
}

int main()
{
    sieve();


    int cnt=0;
    for(int i=2;i<=100000000;i++)
    {
        if(!check(i,i&31))
        {
            cnt++;
            if(cnt%100==1)
                printf("%d\n",i);
        }
    }


}

