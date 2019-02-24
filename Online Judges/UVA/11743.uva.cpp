#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int a[4],temp,arr[20],k,sum1,sum2,tc;
    cin>>tc;
    while(tc--)
    {
        cin>>a[0]>>a[1]>>a[2]>>a[3];
        sum1=0;
        sum2=0;
        k=0;
       for(int i=0;i<4;i++)
       {
           for(int j=0;j<4;j++)
           {
               arr[k++]=a[i]%10;
               a[i]=a[i]/10;
           }
       }

       for(int i=0;i<16;i+=2)
       {
           sum1=sum1+arr[i];

       }

        for(int i=1;i<16;i+=2)
        {
            arr[i]=arr[i]*2;
            if(arr[i]<10)
                sum2=sum2+arr[i];
            else
            {
                sum2=sum2+(arr[i]%10)+(arr[i]/10);
            }
        }
       sum1=sum1+sum2;
       if(sum1%10==0)
        cout<<"Valid"<<endl;
       else
        cout<<"Invalid"<<endl;
    }
    return 0;
}
