#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fact[21];
ll cnt[26];

int main()
{

    fact[0]=1;
    for(int i=1;i<=20;i++)
        fact[i]=i*fact[i-1];

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=tc ; cs++)
    {
        string str;
        ll N;
        cin>>str>>N;

        int len=str.size();
        memset(cnt,0,sizeof(cnt));

        for(int i=0; i<str.size(); i++)
            cnt[str[i]-'a']++;

        ll res=fact[len];
        for(int i=0;i<26;i++)
            res/=fact[cnt[i]];


        printf("Case %d: ",cs);

        if(res<N)
        {
            printf("Impossible\n");
        }
        else
        {
            while(len)
            {

                ll x=fact[len-1];

                for(int i=0; i<26;i++)
                {
                    if(!cnt[i])
                        continue;

                    for(int j=0;j<26; j++)
                    {
                        if(i==j)
                            x/=fact[cnt[j]-1];
                        else
                            x/=fact[cnt[j]];
                    }

                    if(x>=N)
                    {
                        printf("%c",i+'a');
                        len--;
                        cnt[i]--;
                        break;
                    }
                    else
                    {
                        N-=x;
                        x=fact[len-1];
                    }

                }
            }
              printf("\n");
        }




    }







    return 0;
}
