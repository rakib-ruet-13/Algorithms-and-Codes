#include<bits\stdc++.h>
using namespace std;
unsigned long long int power(unsigned long long int base,int p);

int main()
{
    unsigned long long int bamp[100000],temp1,temp2,n,num,i,j;
    int arr1[8],arr2[8],digit,check;

    while(cin>>digit)
    {
        n=0;
        i=power(10,(digit/2)-1);
        while(i<power(10,digit/2))
          {
              j=power(10,(digit/2)-1);
               if(i%2!=0)
                j=j+1;
              while(j<power(10,digit/2))

          {

            temp2=i*j;
            if(temp2<pow(10,digit) && (temp2%100!=0) && (temp2>pow(10,digit-1))&&temp2%2==0)
            {
                temp1=i*power(10,digit/2)+j;
                for(int k=0;k<digit;k++)
                {
                    arr1[k]=temp1%10;
                    temp1=temp1/10;
                }
              for(int k=0;k<digit;k++)
              {
                  arr2[k]=temp2%10;
                  temp2=temp2/10;
              }


              sort(arr1,arr1+digit);
              sort(arr2,arr2+digit);
              //cout<<"sorted"<<endl;

              for(int k=0;k<digit;k++)
                {
                if(arr1[k]==arr2[k])
                check=1;
              else
              {
                  check=0;
                  break;
              }
                }

              if(check==1)
              {
                bamp[n++]=i*j;
                 //cout<<i*j<<endl;
              }
            }
          if(i%2!=0)
            j=j+2;
            else
                j++;
        }
         i++;
          }
          sort(bamp,bamp+n);
            for(int k=0;k<n;k++)
                cout<<bamp[k]<<endl;

    }
    return 0;
}

unsigned long long int power(unsigned long long int base,int p)
{
    for(int i=1;i<p;i++)
        base=base*base;
    return base;
}
