#include<iostream>
#include<algorithm>
#include<vector>

 long long int arr[1000001];

using namespace std;

int main()
{


    long long int n,mx,space,num,i;
    char ch;


    while(cin>>n)
    {

        mx=0;
        space=0;
        for(i=0;i<1000001;i++)
            arr[i]=0;

        for(i=0;i<n;i++)
        {
            cin>>ch;
           cin>>num;
           if(ch=='+')
           {
               if(arr[num]==0)
               {
                   if(space==mx)
                   {
                       space++;
                       mx++;
                   }
                   else
                    space++;

                   arr[num]=1;
               }
           }
           else
           {

              if(arr[num]==1)
              {
                  arr[num]=0;
                  space--;
              }
              else
              {
                  mx++;
              }
           }
        }
        cout<<mx<<endl;

    }
}
