#include<iostream>
using namespace std;

int main()
{
    double len,wid,dep,wig;
    int tc,ans=0;
    cin>>tc;
    while(tc--)
        {
            cin>>len>>wid>>dep>>wig;
            if(((len<=56.00 && wid<=45.00 && dep<=25.00) || (len+wid+dep)<=125.00) && wig<=7.00)
            {
                cout<<1<<endl;
                ans++;
            }
            else
                cout<<0<<endl;
        }
        cout<<ans<<endl;

        return 0;

}
