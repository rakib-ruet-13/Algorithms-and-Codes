#include<bits/stdc++.h>
#include<iostream>
#define MAX 5010


using namespace std;

void Gen_prime(void);
bool sieve[MAX+1];
vector<int>prime;

map<long long int,long long int>prime_fact;
map<long long int,long long int>::iterator it;


vector<long long int>graph[MAX];
int s,t;
void Gen_prime(void)
{

    unsigned long long int num;

    static unsigned long long int i,j;
    for(i=4;i<=MAX;i+=2)
        sieve[i]=1;
    for(i=3;i*i<=MAX;i+=2)
    {
        if(sieve[i]==0)
            for(j=i*i;j<=MAX;j=2*i+j)
            sieve[j]=1;
    }
    prime.push_back(2);
    for(int i=3;i<=MAX;i+=2)
    {
        if(sieve[i]==0)
            prime.push_back(i);
    }
}

int Gen_prime_fact(long long int num)
{

  int i=0;
    while(num!=1 && prime[i]<=sqrt(num))
   {
       while(num%prime[i]==0)
       {
           prime_fact[prime[i]]++;
           num=num/prime[i];
       }


       i++;

   }
   if(num!=1)
   {
       prime_fact[num]++;
   }

}



int bfs(int n,int src)
{

    queue<int>Q;

    int visited[2*MAX],parent[2*MAX],level[2*MAX];

    memset(visited,0,sizeof(visited));

    memset(level,-1,sizeof(level));


    Q.push(src);
    visited[src]=1;
    level[src]=0;

    while(!(Q.empty()))
    {
        int u=Q.front();
        for(int i=0;i<graph[u].size();i++)
        {
           int  v=graph[u][i];

          // cout<<u<<" "<<v<<endl;

            if(visited[v]==0 && v<=t)
            {

                level[v]=level[u]+1;
                parent[v]=u;
                visited[v]=1;
                Q.push(v);


            }


        }
        Q.pop();


    }

   // cout<<"ojojj";

   // cout<<level[t]<<endl;
    return level[t];


}


int main()
{
    Gen_prime();

    for(long long int i=1; i<MAX-2 ;i++)
    {
        Gen_prime_fact(i);

        for(it=prime_fact.begin() ;it!=prime_fact.end();it++)
        {
            if(it->first!=1 && it->first!=i)
            {
                long long p=i+it->first;
                  graph[i].push_back(p);
            }

        }

        prime_fact.clear();
    }

    int tc;
    scanf("%d",&tc);

    for(int cs=1; cs<=tc ;cs++)
    {
        scanf("%d %d",&s,&t);


        if(t<s)
            printf("Case %d: -1\n",cs);
        else if(t==s)
            printf("Case %d: 0\n",cs);
        else if(sieve[s]==0)
        {
             printf("Case %d: -1\n",cs);
        }
        else
        {
            //cout<<"in"<<endl;
            int res=bfs(1001,s);
            if(res==-1)
             printf("Case %d: -1\n",cs);
            else
           printf("Case %d: %d\n",cs,res);

        }


    }

    return 0;


}
