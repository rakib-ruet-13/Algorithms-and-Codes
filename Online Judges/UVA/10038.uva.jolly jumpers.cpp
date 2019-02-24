#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int arr1[8000],arr2[8000],n,i,j;
    while(cin>>n)
    {
        j=1;
        for(i=0;i<n;i++)
            cin>>arr1[i];
        for(i=0;i<n-1;i++)
            arr2[i]=abs(arr1[i+1]-arr1[i]);
        sort(arr2,arr2+i);

        for(i=1;i<n;i++)
            if(arr2[i]==arr2[i-1])
        {
          j=0;
          break;
        }
        if(j==0)
        cout<<"Not jolly"<<endl;
        else
            cout<<"Jolly"<<endl;


    }

    return 0;
}
