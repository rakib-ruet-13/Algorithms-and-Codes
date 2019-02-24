#include<iostream>
#include<bits/stdc++.h>

using namespace std;


string st;
char s[1001];
int n;

int pal[1001][1001];

int is_palin(int i, int j)
{
    if(i>=j)
        return 1;

    if(pal[i][j]!=-1)
        return pal[i][j];

    is_palin(i+1,j);
    is_palin(i,j-1);

    if(st[i]==st[j])
        return pal[i][j]=is_palin(i+1,j-1);
    else
        return pal[i][j]=0;

}

int dp[1001][1001];

int solve(int pos,int pre)
{
    if(pos>n)
    {
        if(is_palin(pre,pos-1))
            return 1;
        else
            return n;
    }

    if(dp[pos][pre]!=-1)
        return dp[pos][pre];

    int res=n;

    if(is_palin(pre,pos))
       res=min(res,1+solve(pos+1,pos+1));

    res=min(res,solve(pos+1,pre));

    return dp[pos][pre]=res;




}

int main()
{

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc ; cs++)
    {
        memset(pal,-1,sizeof(pal));
        scanf("%s",s);

        st.clear();
        st+='0';
        n=strlen(s);

        for(int i=0; i<n; i++)
            st+=s[i];

        is_palin(1,n);

        memset(dp,-1,sizeof(dp));

        printf("Case %d: %d\n",cs,solve(1,1));



    }





    return 0;
}
