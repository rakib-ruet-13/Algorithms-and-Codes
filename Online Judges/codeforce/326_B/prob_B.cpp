#include<bits\stdc++.h>
#define MAX 10000001
using namespace std;
void Gen_prime(void);
bool sieve[MAX];
long long int Prime_fact[10000000];
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

long long int Gen_prime_fact(long long int num)
{
    long long int sum;

  vector<long long int>vct;

  //long long int temp,i,j;
  //temp=num;
  vct.push_back(1);

  if(num%2==0)
  {
      do
      {
      vct.push_back(2);
      num=num/2;
      }
      while(num%2==0);

  }


    for(long int i=3;i*i<=num && i<10000000 ;i+=2)
    {
        if(i<10000000)
        if(sieve[i]==0)
        {
            if(num%i==0)
            do
            {
                vct.push_back(i);
                num=num/i;
            }
            while(num%i==0);
        }
    }
    vct.push_back(num);
   // cout<<num<<endl;

    sort(vct.begin(),vct.end());

      //for(int i=0;i<vct.size();i++)
       // cout<<vct[i]<<endl;
    for(int i=0;i<vct.size()-1;i++)
    {
        //cout<<vct[i]<<"  "<<vct[i+1]<<endl;
        if(vct[i]==vct[i+1])
        {
            vct[i]=1;
        }
    }
    sum=1;

     // for(int i=0;i<vct.size();i++)
        //cout<<vct[i]<<endl;

    for(int i=0;i<vct.size();i++)

        sum=sum*vct[i];

     vct.clear();

         return sum;


}

int main()
{
    long long int num;


    Gen_prime();


      cin>>num;

      cout<<Gen_prime_fact(num)<<endl;


}

