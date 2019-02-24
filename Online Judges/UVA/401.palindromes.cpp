#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    string str,str2,str3,str4;
    int mp,ms,l,check;
    while(getline(cin,str))
    {
        mp=1;
        ms=1;
        check=1;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='A'||str[i]=='H' || str[i]=='I' || str[i]=='M' || str[i]=='O' || str[i]=='T'|| str[i]=='U' || str[i]=='V'|| str[i]=='W'||str[i]=='X' || str[i]=='Y'||str[i]=='8')
            {
                mp=1;

            }
            else
            {
                mp=0;
                break;
            }
        }
        str2=str;
        reverse(str2.begin(),str2.end());
        if(str2==str && mp==0)
            cout<<str<<" -- "<<"is a regular palindrome."<<endl;
        else if(str2==str && mp==1)
            cout<<str<<" -- "<<"is a mirrored palindrome."<<endl;
        else if(str2!=str)
        {
            str3=str;
            if(str.size()%2==0)
                l=str.size()/2;
            else
            {
                l=str.size()/2+1;
                int i=l-1;
                if(str[i]=='E'||str[i]=='3'||str[i]=='J'||str[i]=='L'||str[i]=='S'||str[i]=='2'||str[i]=='Z'||str[i]=='5')
                    check=0;
            }
            for(int i=0;i<l;i++)
            {

                if(str[i]=='3')
                    {
                        str[i]='E';

                    }

                else if(str[i]=='E')
                    str[i]='3';

                else if(str[i]=='J')
                    str[i]='L';

                else if(str[i]=='L')
                    str[i]='j';

                else if(str[i]=='S')
                    str[i]='2';
                else if(str[i]=='2')
                    str[i]='S';

                else if(str[i]=='Z')
                    str[i]='5';
                else if(str[i]=='5')
                    str[i]='Z';

            }
            for(int i=0;i<str.size();i++)
            if(str[i]=='A'||str[i]=='H' || str[i]=='I' || str[i]=='M' || str[i]=='O' || str[i]=='T'|| str[i]=='U' || str[i]=='V'|| str[i]=='W'||str[i]=='X' || str[i]=='Y'||str[i]=='8'||str[i]=='E'||str[i]=='3'||str[i]=='J'||str[i]=='L'||str[i]=='S'||str[i]=='2'||str[i]=='Z'||str[i]=='5')
                  {
                     ms=1;
                  }
                  else
                  {
                      ms=0;
                      break;
                  }


                    str4=str;

                reverse(str4.begin(),str4.end());

                if(str4==str && ms!=0 && check!=0)
                    cout<<str3<<" -- "<<"is a mirrored string."<<endl;
                else
                    cout<<str3<<" -- "<<"is not a palindrome."<<endl;





            }
            cout<<endl;
        }

return 0;
}
