#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);
    getchar();
    for(int cs=1; cs<=tc ;cs++)
    {

        string s1,s2;
        vector<char>str1,str2;

        getline(cin,s1);
        getline(cin,s2);


        for(int i=0 ;i<s1.size() ;i++)
        {
            if(s1[i]!=' ')
            {
                if(s1[i]<'a')
                {
                    str1.push_back((char)(s1[i]+32));
                }
                else
                {
                    str1.push_back((char)(s1[i]));
                }
            }
        }

         for(int i=0 ;i<s2.size() ;i++)
        {
            if(s2[i]!=' ')
            {
                if(s2[i]<'a')
                {
                    str2.push_back((char)(s2[i]+32));
                }
                else
                {
                    str2.push_back((char)(s2[i]));
                }
            }
        }

        sort(str1.begin(), str1.end());
         sort(str2.begin(), str2.end());

        if(str1==str2)
            printf("Case %d: Yes\n",cs);
        else
            printf("Case %d: No\n",cs);


      str1.clear();
      str2.clear();




    }
}
