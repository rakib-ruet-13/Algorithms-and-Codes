#include<iostream>
using namespace std;

int main()
{
    long long int tc,a,b,c,i=1;
    cin>>tc;
    while(tc--)
    {

        cin>>a>>b>>c;
        cout<<"Case "<<i++<<": ";
        if((a+b)<=c || (a+c)<=b || (b+c)<=a || a<=0 || b<=0 || c<=0 )
            cout<<"Invalid"<<endl;
        else if(a==b && a==c)
            cout<<"Equilateral"<<endl;
        else if(a==b || a==c || b==c)
            cout<<"Isosceles"<<endl;
        else
            cout<<"Scalene"<<endl;
    }
    return 0;
}
