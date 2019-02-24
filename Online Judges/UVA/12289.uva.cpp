#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int tc,cnt;
    string str,str1;
    cin>>tc;
    getline(cin,str1);
    while(tc--)
    {
        cin>>str;
        if(str.size()==5)
            cout<<3<<endl;
        else
        {
            cnt = 0;

            if ( str[0] == 'o' ) cnt++;
            if ( str[1] == 'n' ) cnt++;
            if ( str[2] == 'e' ) cnt++;

            if ( cnt >= 2 )
                cout<<1<<endl;
            else
                cout<<2<<endl;
        }
    }
    return 0;
}
