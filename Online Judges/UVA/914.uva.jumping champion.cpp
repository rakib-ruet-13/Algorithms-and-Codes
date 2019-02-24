#include<iostream>
#include<algorithm>
#define MAX 10000000
using namespace std;
void Gen_prime(void);
bool sieve[MAX];
long long int arr_prime[1000000];
long long int arr_dis[1000000],arr2[1000000];

int main()
{
    Gen_prime();

    bool check;
    long long int num,i,j,up,ll,tc,cnt1;
    cin>>tc;
    while(tc--)
    {
        cnt1=0;
        cin>>ll>>up;

         if(ll==2)
         {
             arr_prime[++cnt1]=2;
             ll++;
         }
        for(i=ll;i<=up;i+=2)
        {
            if(!sieve[i])
                {
                    arr_prime[++cnt1]=i;
                    cout<<arr_prime[cnt1]<<endl;
                }
        }
        for(i=1;i<up;i++)
        {
          arr_dis[arr_prime[i+1]-arr_prime[i]]++;
          cout<< arr_prime[i+1]-arr_prime[i]<<endl;
        }
        for(i=0;i<up;i++)
            {
                arr2[i]=arr_dis[i+1];
                cout<<"arr dis"<<arr_dis[i+1]<<endl;

            }
        sort(arr2,arr2+up,greater<long long int>());

        if(arr_dis[0]==arr_dis[2])
            cout<<"no jumper"<<endl;
        else
            {
                for(i=1;i<=up;i++)
                if(arr_dis[i]==arr2[0])
                {
                    cout<<i;
                    break;
                }
            }




    }
}

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

