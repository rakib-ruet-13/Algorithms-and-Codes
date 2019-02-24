#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Max_node 80001
#define Max_len 100011

string st;
char S[Max_len];
int node[Max_node][60];
int root;
int nnode;
int is_word[Max_node];

void init()
{
    root=0;
    nnode=0;
    for(int i=0; i<60; i++)
        node[root][i]=-1;
    memset(is_word,0,sizeof(is_word));
}

void add()
{
    scanf("%s",S);
    int len=strlen(S);

    if(len>2)
      sort(S+1,S+(len-1));

    int now=root;

    for(int i=0; i<len; i++)
    {
        if(node[now][S[i]-'A']==-1)
        {
            node[now][S[i]-'A']=++nnode;
            for(int k=0; k<60; k++)
            {
                node[nnode][k]=-1;
            }
        }
        now=node[now][S[i]-'A'];

    }
    is_word[now]++;
}

int Find(string str)
{
    int len=str.size();


    if(str.size()>2)
    sort(str.begin()+1,str.end()-1);

    int now=root;

    for(int i=0; i<len ; i++)
    {
        if(node[now][str[i]-'A']==-1)
            return 0;
        else
            now=node[now][str[i]-'A'];
    }

    return is_word[now];

}



int main()
{
    int tc;
    scanf("%d",&tc);


    for(int cs=1 ; cs<= tc ;cs++)
    {
         init();
         int n;
         scanf("%d",&n);

         while(n--)
            add();

          int q;
         scanf("%d",&q);

         getchar();


         printf("Case %d:\n",cs);

         while(q--)
         {
             gets(S);

             int len=strlen(S);
             string str;
             int res=1;

             for(int i=0;i<len ; i++)
             {
                 if(S[i]==' ')
                 {
                     if(str.size()>0)
                     {
                         res*=Find(str);
                         str.clear();
                     }
                 }
                 else
                 {
                     str+=S[i];
                 }
             }

             if(str.size()>0)
                res*=Find(str);
            str.clear();

            printf("%d\n",res);
         }

    }


    return 0;
}
