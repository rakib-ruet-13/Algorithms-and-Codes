#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    string str;
    long long int h,m,i;
    double ho,mi,ans;
    while(getline(cin,str))
    {
        if(str.size()==4)
        {
            h=(int)str[0]-48;
            m=((int)str[2]-48)*10+(str[3]-48);
        }
        else
        {
            h=((int)str[0]-48)*10+(str[1]-48);
            m=((int)str[3]-48)*10+(str[4]-48);
        }
        if(h==0 && m==0)
            break;
        else
        {
           ho=(double)h+  (double)m/60;
           mi=m;

           ho=ho*30;
           mi=mi*6;

           if(ho<mi)
            ans=mi-ho;
           else
            ans=ho-mi;

           if(ans>180.00000000)
            ans=360.00000000-ans;
           cout<<fixed<<setprecision(3);
           cout<<ans<<endl;



        }
    }

}
