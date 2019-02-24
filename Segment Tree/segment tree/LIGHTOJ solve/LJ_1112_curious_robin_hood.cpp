#include<bits/stdc++.h>
#include<iostream>

#define Max 100010

#define ll long long
#define pb push_back
#define pi acos(-1.0000)
#define mp make_pair
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define mem(x,a) memset(x,a,sizeof(a))
#define sz size()
#define scan(a) scanf("%lld",&a);
#define scani(a) scanf("%d",&a);
#define print(a) printf("%lld\n",a);
#define printi(a) printf("%d\n",a);
#define uu first
#define vv second
#define FIO  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define CS(i) cout<<"Case :"<<i<<"\n";

using namespace std;



int T[4*Max+4];
int arr[Max+4];


int n;
int val;


///*****[L,R) format , oot starts with 1*****//

void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = arr[l];
		return ;
	}
	int mid = (l+r)/2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	T[id] = T[2 * id] + T[2 * id + 1];
}

void update(int p,int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id]+= val;
		return ;
	}
	int mid = (l+r)/2;
	if(p < mid)
		update(p, 2 * id, l, mid);
	else
		update(p, 2 * id + 1, mid, r);
	T[id] = T[2 * id] + T[2 * id + 1];
}




int ask(int x,int y,int id = 1,int l = 0,int r = n){// [x, y)
	if(x >= r or l >= y)	return 0;// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)	// [l,r) is a subset of [x,y)
		return T[id];
	int mid = (l + r)/2;
	return ask(x, y, id * 2, l, mid) +ask(x, y, id*2+1, mid, r) ;
}





int main()
{
    int tc;
    scanf("%d",&tc);

    for(int cs=1 ; cs<=  tc ; cs++)
    {
        int n;
        scani(n);
        int q;
        scani(q);


        rep(i,0,n-1)
        {
            scani(arr[i]);
        }
        build(1,0,n);


        printf("Case %d:\n",cs);

        while(q--)
        {
            int p;
            scani(p);

            if(p==1)
            {
                int x;
                scani(x);

                val=-ask(x,x+1,1,0,n);
                printf("%d\n",-val);

                update(x,1,0,n);
            }
            else if(p==2)
            {
                int x;
                scani(x);
                scani(val);
                update(x,1,0,n);

            }
            else
            {
                int x,y;
                scani(x);
                scani(y);

                if(x>y)
                    swap(x,y);

                printf("%d\n",ask(x,y+1,1,0,n));

            }
        }




    }



    return 0;
}

