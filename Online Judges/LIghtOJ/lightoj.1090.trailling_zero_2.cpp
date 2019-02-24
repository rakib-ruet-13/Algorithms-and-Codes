#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int arr2[1000010];
int arr5[1000010];

int pq2;
int pq5;

void ncr()
{
    arr2[0]=0;
    arr5[0]=0;

    for(int i=1;i<=1000000;i++)
    {
        arr2[i]=arr2[i-1];
        arr5[i]=arr5[i-1];

        int k=i;

        while(k%2==0)
            {
                arr2[i]++;
                k=k/2;
            }
        while(k%5==0)
        {
            arr5[i]++;
            k=k/5;
        }


    }

}

void ppq(int p,int q)
{
    pq2=0;
    pq5=0;

    while(p%2==0)
    {
        p=p/2;
        pq2++;
    }
    while(p%5==0)
    {
        p=p/5;
        pq5++;
    }
    pq2*=q;
    pq5*=q;
}


int main()
{

    int tc;
    ncr();

    scanf("%d",&tc);

    for(int cs=1;cs<=tc;cs++)
    {
        int n,r,p,q;

        scanf("%d %d %d %d",&n,&r,&p,&q);
        ppq(p,q);

        long long ans;
        ans=min(arr2[n]-arr2[n-r]-arr2[r]+pq2, arr5[n]-arr5[n-r]-arr5[r]+pq5);

        printf("Case %d: %lld\n",cs,ans);


    }



}
