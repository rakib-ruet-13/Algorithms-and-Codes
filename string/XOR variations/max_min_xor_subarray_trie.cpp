#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Max_node 1000100
#define Max 1010000
#define ull unsigned long long

ull check(ull N,int pos){ return N & (1uLL<<pos);}

int node[Max_node][2];
int root;
int nnode;

ull arr[Max];


void init()
{
    root=0;
    nnode=0;
    for(int i=0; i<2; i++)
        node[root][i]=-1;


}

void add(ull num)
{

    int now=root;

    for(int i=60; i>=0; i--)
    {
        ull curr_bit;

        if(check(num,i))
            curr_bit=1uLL;
        else
            curr_bit=0uLL;

        if(node[now][curr_bit]==-1)
        {
            node[now][curr_bit]=++nnode;
            for(int k=0; k<2; k++)
            {
                node[nnode][k]=-1;

            }
        }
        now=node[now][curr_bit];

    }
}

ull res1,res2;

void Find(ull num)
{
    ull now1,now2;

    now1=now2=root;

    res1=res2=0uLL;

    for(int i=60; i>=0 ; i--)
    {
         ull curr_bit;

        if(check(num,i))
            curr_bit=1uLL;
        else
            curr_bit=0uLL;

        if(node[now1][1uLL-curr_bit] != -1)
        {

            res1^=(((ull)(1uLL-curr_bit))<<i);
            now1=node[now1][1uLL-curr_bit];
        }
        else
        {
            res1^=(((ull)(curr_bit))<<i);
            now1=node[now1][curr_bit];
        }

         if(node[now2][curr_bit] == -1)
        {
            res2^=(((ull)(1uLL-curr_bit))<<i);
            now2=node[now2][1uLL-curr_bit];
        }

        else
        {
            res2^=(((ull)(curr_bit))<<i);
            now2=node[now2][curr_bit];
        }

    }

    res1=res1^num;
    res2=res2^num;

}

int max_min_xor_sub_array(int n)
{
    init();

    ull mx,mn;
    mx=0uLL;
    mn=11111111111111;

    ull pre=0uLL;
    add(pre);

    for(int i=0; i<n ; i++)
    {
        pre=pre^arr[i];



        Find(pre);
        mn=min(mn,res2);


        add(pre);
        Find(pre);
        mx=max(mx,res1);

    }

    printf("%llu %llu\n",mx,mn);


}



int main()
{
    int tc;
    //freopen("input.txt","r",stdin);

    scanf("%d",&tc);

    for(int cs=1 ; cs<= tc ;cs++)
    {
      int n;

      scanf("%d",&n);

      for(int i=0; i<n ; i++)
      {
          scanf("%llu",&arr[i]);
      }

      printf("Case %d: ",cs);
      max_min_xor_sub_array(n);

    }




    return 0;
}
