#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long int arr[4],tc;
    cin>>tc;
    while(tc--)
    {
        cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
        sort(arr,arr+4);
        if(arr[0]==arr[3])
          cout<<"square"<<endl;
        else if(arr[0]==arr[1] && arr[2]==arr[3])
           cout<<"rectangle"<<endl;
           else if(arr[3]>=arr[0]+arr[1]+arr[2])
                cout<<"banana"<<endl;
                 else
                 cout<<"quadrangle"<<endl;

    }
    return 0;

}
