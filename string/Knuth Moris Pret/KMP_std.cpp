#include<iostream>
#include<bits/stdc++.h>
#define Max 10010

using namespace std;

int pi[Max];
string P;
string T;
int cnt[Max]; /** counting all prefix as substring **/

typedef long long ll;

/**P#T count***/
int failure_cnt;
int prefix_size;

/*** for unique substring***/
int max_match;

long long unique_substring(string str);
int prefix_fun();
int kmp_match();
long long cnt_all_prefix_match();
int concate(string str);

int prefix_fun()
{
    failure_cnt=0; /**** Needed for P#T */
    max_match=-1;

    int now;
    pi[0]=now=-1;

    int len=P.size();

    for(int i=1; i<len ; i++)
    {
        while(now!=-1 && P[now+1]!=P[i])
            now=pi[now];
        if(P[now+1]==P[i])
            pi[i]=++now;
        else
            pi[i]=now=-1;

        max_match=max(max_match,now);

        if(now==prefix_size-1)
            failure_cnt++;
    }
}



int kmp_match()
{
     int now=-1;
    int n=T.size();
    int m=P.size();

    for(int i=0; i<n ; i++)
    {
        while(now!=-1 && P[now+1]!=T[i])
            now=pi[now];

        if(P[now+1]==T[i])
            ++now;
        else
            now=-1;

        if(now==m-1)
        {
            return 1;
        }
    }
    return 0;


}



int main()
{

    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc ;cs++)
    {
        cin>>T;
        cout<<concate(T)<<endl;
    }
    return 0;
}





long long cnt_all_prefix_match()
{
    memset(cnt,0,sizeof(cnt));

    int now=-1;
    int n=T.size();
    int m=P.size();

    for(int i=0; i<n ; i++)
    {
        while(now!=-1 && P[now+1]!=T[i])
            now=pi[now];

        if(P[now+1]==T[i])
            ++now;
        else
            now=-1;
        cout<<now<<endl;

        if(now>=0)
            cnt[now]++;

        if(now==m-1)
            now=pi[now];
    }

    for(int i=m-1; i>=0 ; i--)
    {
        if(cnt[i]>0 && pi[i]!=-1)
            cnt[pi[i]]+=cnt[i];
    }

    long long res=0;
    for(int i=0; i<m ; i++)
    res+=cnt[i];

    return res;

}


long long unique_substring(string str)

{
    ll res=0;
    for(int i=0; i<str.size() ; i++)
    {
        P.clear();

        for(int j=i; j<str.size() ;j++)
        {
            P+=str[j];
        }
         ll len=P.size();
        prefix_fun();
        res+=len-(max_match+1);
    }
    return res;
}


int concate(string str)
{
    P.clear();
    P=str;
    prefix_fun();
    int n=str.size();
    int len=pi[n-1]+1;

    if(len>0 && n%(n-len)==0)
        return n-len;
    else
        return 0;
}

