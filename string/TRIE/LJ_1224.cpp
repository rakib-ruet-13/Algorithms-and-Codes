#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Max_node 1000000
#define Max_len 53

string st;
char S[Max_len];
int node[Max_node][4];
int root;
int nnode;
int is_word[Max_node];
int mx;

map<char,int>mymap;

void init()
{

    mymap.clear();
    mymap['A']=0;
    mymap['C']=1;
    mymap['G']=2;
    mymap['T']=3;

    root=0;
    nnode=0;
    mx=0;


        node[root][0]=node[root][1]=node[root][2]=node[root][3]=-1;
    memset(is_word,0,sizeof(is_word));
}


void add()
{
    scanf("%s",S);
    int len=strlen(S);

    int now=root;

    for(int i=0; i<len; i++)
    {
        if(node[now][mymap[S[i]]]==-1)
        {
            node[now][mymap[S[i]]]=++nnode;
              node[nnode][0]=node[nnode][1]=node[nnode][2]=node[nnode][3]=-1;
        }
        now=node[now][mymap[S[i]]];

         is_word[now]+=(i+1);

         mx=max(mx,is_word[now]);


    }



}






int main()
{
    int tc;
    scanf("%d",&tc);


    for(int cs=1 ; cs<= tc ;cs++)
    {

        int n;
        scanf("%d",&n);

        init();

        while(n--)
            add();

        printf("Case %d: %d\n",cs,mx);

    }


    return 0;
}

