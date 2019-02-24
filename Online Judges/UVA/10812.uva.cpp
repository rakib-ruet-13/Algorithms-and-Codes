#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    long int tc,fs,fd;
    cin>>tc;
    while(tc)
    {
        cin>>fs>>fd;
        if(fd>fs || (fd+fs)%2==1)
            cout<<"impossible\n";
        else
        {
            cout<<(fd+fs)/2<<" "<<(abs(fd-fs))/2<<endl;
        }

        tc--;
    }
        return 0;
}
