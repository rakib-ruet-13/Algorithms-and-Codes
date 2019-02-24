#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    int a,b,c,sum,temp,i,j;
    int arr1[32],arr2[32],arr3[32];
    while(cin>>a>>b)
    {

        if(a<0)
            a=-a;
        if(b<0)
            b=-b;

       for(i=0;i<32;i++)
        arr1[i]=0;
        for(i=0;i<32;i++)
           arr2[i]=0;


       sum=0;
       i=0;

    do
    {
        temp=a%2;
        arr1[i++]=temp;
        a=a/2;
    }
    while(a!=0);
       j=0;
    do
    {
        temp=b%2;
        arr2[j++]=temp;
        b=b/2;
    }
    while(b!=0);


     for(i=0;i<32;i++)
     {
         if(arr1[i]!=arr2[i])
            arr3[i]=1;
         else
            arr3[i]=0;
     }


     for(i=31;i>=0;i--)
     {
         sum+=arr3[i]*(pow(2,i));
     }
     cout<<sum<<endl;


}

return 0;

}
