#include<iostream>
#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define uu first
#define vv second
#define mem(x,val) memset(x,val,sizeof(x))
#define REP(i,n) for(int i=1; i<=n ;i++)
#define rep(n) for(int i=0; i<n;i++)
#define pi acos(-1.0000)
#define all(x) (x.begin(),x.end())
#define Max 100100


using namespace std;

map<int, int >mymap,M;
map<int, int >:: iterator it;

ll read;


int arr[3001000];
int sum[3001000];

int main()
{

    int n,q;

    cin>>n>>q;

    read=0;

    mem(arr,0);
    ll cnt=0;

    for(int i=1; i<=q;i++)
    {
        int flag,app;

        scanf("%d %d",&flag,&app);

        if(flag==1)
        {
            cnt+=1;
            arr[app]++;
            mymap[i]+=app;

        }
        else if(flag==2)
        {
            cnt-=arr[app];
        }
        else if(flag==3)
        {
            int t=app;


             t=t-read;

             if(t>0)
             cnt-=t;


             if(cnt<0)
                cnt=0;




            for( it=mymap.begin() ; it!=mymap.end() ; it++)
            {
                if(t>0)
                {
                    if( arr[mymap[it->first]]>t)
                    {
                            arr[mymap[it->first]]-=t;
                            t=0;
                    }
                    else
                    {
                        t=t-arr[mymap[it->first]];
                        arr[mymap[it->first]]=0;

                    }
                }
                else
                {

                    M[it->first]=it->second;


                }

            }

            read=max(read,(ll)app);

            mymap.clear();
            mymap=M;
            M.clear();

            t=0;


        }

        cout<<cnt<<endl;



    }



    return 0;
}

