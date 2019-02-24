#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Max_node 100010
#define Max_len 101

string st;
char S[Max_len];
int node[Max_node][26];
int root;
int nnode;
int is_word[Max_node];

int flag;

void init()
{
    root=0;
    nnode=0;
    flag=1;

    for(int i=0; i<10; i++)
        node[root][i]=-1;
    memset(is_word,0,sizeof(is_word));
}




int Find()
{
    int len=strlen(S);
    int now=root;

    for(int i=0; i<len ; i++)
    {
        if(node[now][S[i]-'0']==-1)
            return 0;
        else
            now=node[now][S[i]-'0'];
    }

    flag=0;

    return 0;

}

void add()
{
    scanf("%s",S);
    int len=strlen(S);

    Find();

    int now=root;

    for(int i=0; i<len; i++)
    {
        if(node[now][S[i]-'0']==-1)
        {
            node[now][S[i]-'0']=++nnode;
            for(int k=0; k<10; k++)
            {
                node[nnode][k]=-1;
            }
        }
        now=node[now][S[i]-'0'];

        if(is_word[now]==1)
            flag=0;

    }

    if(is_word[now]==1)
        flag=0;

    is_word[now]=1;
}




int main()
{
    freopen("input.txt","r",stdin);

    int tc;
    scanf("%d",&tc);


    for(int cs=1 ; cs<= tc ;cs++)
    {
        int n;
        scanf("%d",&n);

        init();

        flag=1;

        while(n--)
            add();

        printf("Case %d: ",cs);

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");

    }


    return 0;
}

