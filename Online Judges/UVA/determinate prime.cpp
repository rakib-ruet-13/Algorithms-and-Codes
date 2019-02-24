#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#define MAX 32000
using namespace std;


vector<int>v;
struct ditermine_prime
{
    int num;
    int dis;
    int cnt;
};

struct ditermine_prime dprime[3000];
int t=0;

void Gen_prime(void);
bool sieve[MAX];
void Gen_prime(void)
{

    unsigned long long int num;

    static unsigned long long int i,j;
    for(i=4;i<MAX;i+=2)
        sieve[i]=1;
    for(i=3;i*i<MAX;i+=2)
    {
        if(sieve[i]==0)
            for(j=i*i;j<MAX;j=2*i+j)
            sieve[j]=1;
    }
    v.clear();
    v.push_back(2);
    for(i=3;i<MAX;i+=2)
    {
        if(sieve[i]==0)
            v.push_back(i);
    }

}

void Gen_det_prime()
{
    int l,i,temp;
    l=v.size();
   for(i=0;i<l;i++)
   {
       temp=i;
       int count=0;
      while(v[i+1]-v[i]==v[i+2]-v[i+1])
      {

        count++;
        i=i+1;
      }
      if(count>=1)
      {
        dprime[t].num=v[temp];
        dprime[t].cnt=(2+count);
        dprime[t].dis=v[temp+1]-v[temp];

        t++;
      }
   }
}
int main()
{
    int i,ll,up,temp;
   Gen_prime();

   Gen_det_prime();
   while(cin>>ll>>up && (ll||up))
   {
       if(ll>up)
        swap(ll,up);
        if(up>32000)
            up=32000;
       for(i=0;i<t;i++)
       {
           if(dprime[i].num>=ll && (dprime[i].num+(dprime[i].dis*(dprime[i].cnt-1)))<=up)
           {
               temp=0;
               for(int j=1;j<=(dprime[i].cnt);j++)
                {
                    cout<<dprime[i].num+temp;
                    temp=temp+dprime[i].dis;
                    if(j!=dprime[i].cnt)
                        cout<<" ";

                }
                cout<<endl;

           }
       }
   }
   return 0;
}

