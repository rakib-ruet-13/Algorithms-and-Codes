#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int arr[10009],i=0;

    while(cin>>arr[i++])
    {
        sort(arr,arr+i);
         if(i%2==0)
            cout<<(arr[i/2]+arr[i/2-1])/2<<endl;
         else
            cout<<arr[i/2]<<endl;

    }
    return 0;
}
