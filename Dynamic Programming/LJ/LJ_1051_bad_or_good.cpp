#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char s[1001];
string st;

int n;

int dp[101][10][10][3];

int solve(int pos,int cntv,int cntc,int pre)
{
    if(cntv>=3)
        return 0;
    if(cntc>=5)
        return 0;
    if(pos>n)
        return 1;

    if(dp[pos][cntv][cntc][pre]!=-1)
        return dp[pos][cntv][cntc][pre];

    int res=0;

    if(st[pos]=='?')
    {
        if(pre==0)
        {
            res+=solve(pos+1,cntv+1,0,0)+solve(pos+1,0,1,1);
        }
        else
        {
            res+=solve(pos+1,0,cntc+1,1)+solve(pos+1,1,0,0);
        }

    }
    if(st[pos]=='V')
        res+=solve(pos+1,cntv+1,0,0);

    if(st[pos]=='C')
        res+=solve(pos+1,0,cntc+1,1);

    return dp[pos][cntv][cntc][pre]=res;

}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc ; cs++)
    {
        scanf("%s",s);

        n=strlen(s);
        st.clear();

        st+='0';

        for(int i=0;i<n; i++)
        {
            if(s[i]=='?')
                st+=s[i];
            else if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                st+='V';
            else
                st+='C';
        }

        int flag_bad=0;



        int cnt1,cnt2;
        cnt1=cnt2=0;

        for(int i=1; i<=n; i++)
        {
            if(st[i]=='V' || st[i]=='?')
                cnt1++;
            else
                cnt1=0;

            if(st[i]=='C' || st[i]=='?')
                cnt2++;
            else
                cnt2=0;

            if(cnt1>=3 || cnt2>=5)
            {
                flag_bad=1;
                break;
            }
        }
        if(flag_bad==0)
            printf("Case %d: GOOD\n",cs);
        else
        {
            memset(dp,-1,sizeof(dp));

            if(solve(1,0,0,1) || solve(1,0,0,0))
                printf("Case %d: MIXED\n",cs);
            else
                printf("Case %d: BAD\n",cs);
        }

    }



    return 0;
}
