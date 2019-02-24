#include<iostream>
using namespace std;

int main()
{
    long int tc,arr[3],i,j,sum,n,cst,cnt;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        for(i=2;i>=0;i--)
            cin>>arr[i];

            cst=8*n;
            sum=0;
            cnt=0;

                   while(cst>sum)

                    if(arr[0]!=0)
                   {
                       sum=sum+10*arr[0]-(10*arr[0])%8;
                       arr[0];
                   }
                    cnt=cnt+arr[0];
                    sum=sum+5*arr[1]-(5*arr[1])%8;
                    cnt=cnt+arr[1];
                    cnt=cnt+(cst-sum);


                    cout<<cnt<<endl;



    }





}
