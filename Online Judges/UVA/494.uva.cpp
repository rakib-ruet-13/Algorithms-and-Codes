#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string str;
    int cnt;
    int flag,len,i,j;

    while(getline(cin,str))
    {

        cnt=0;
        len=str.size();

        for(i=0;i<len-1;i++)
            if(('a'<=str[i] && str[i]<='z') ||  ('A'<=str[i] && str[i]<='Z'))
            if(!(('a'<=str[i+1] && str[i+1]<='z') ||  ('A'<=str[i+1] && str[i+1]<='Z')))
            cnt++;

             if(('a'<=str[len-1] && str[len-1]<='z') ||  ('A'<=str[len-1] && str[len-1]<='Z'))
                cnt++;
        cout<<cnt<<endl;


    }

    return 0;
}
