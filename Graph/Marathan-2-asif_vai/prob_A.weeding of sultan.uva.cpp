#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    string str,str2;
    int arr[26][26];

    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc;cs++)
    {
        cin>>str;

        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
        {
            arr[i][j]=0;
        }

        int l=str.size();

        for(int i=0;i<l;i++)
        {
            if(i+1<l)

            {
                 if(i+2<l && i>0)
                     {
                         if(str[i+1]==str[i+2] && str[i]==str[i-1]);
                         else
                         {
                             if(str[i]!=str[i+1] || arr[str[i]-'A'][str[i]-'A']<2)
                             {
                                 if(i>0 )
                                    if( arr[str[i-1]-'A'][str[i-1]-'A']<2);
                                    else
                                    {
                                          arr[str[i]-'A'][str[i+1]-'A']++;
                                          arr[str[i+1]-'A'][str[i]-'A']++;
                                    }
                                else
                                    {
                                          arr[str[i]-'A'][str[i+1]-'A']++;
                                          arr[str[i+1]-'A'][str[i]-'A']++;

                                    }


                             }

                         }
                     }
                 else
                 {
                     if(str[i]!=str[i+1] || arr[str[i]-'A'][str[i]-'A']<2)
                     {

                                          arr[str[i]-'A'][str[i+1]-'A']++;
                                          arr[str[i+1]-'A'][str[i]-'A']++;
                     }

                 }



            }
             arr[str[i]-'A'][str[i]-'A']++;

        }



         printf("case %d:\n",cs);

         for(int i=0;i<26;i++)
           {

            int cnt=0;
            for(int j=0;j<26;j++)

            {
                cout<<arr[i][j]<<" ";
                if(arr[i][j]>0)
                    cnt++;
            }
            cout<<endl;
            if(cnt==1)
                printf("%c = %d\n",char('A'+i),cnt);
            else if(cnt>1)
                printf("%c = %d\n",char('A'+i),cnt-1);


           }



    }



}
