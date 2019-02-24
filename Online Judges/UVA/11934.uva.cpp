#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int a,b,c,d,L,i,cnt,num;
    while(cin>>a>>b>>c>>d>>L && d!=0)
    {
        cnt=0;
        for(i=0;i<=L;i++)
        {
            num=a*i*i+b*i+c;
            if(num%d==0)
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
