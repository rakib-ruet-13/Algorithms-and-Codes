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



int T[8*Max+4];


int n;

int arr[Max*2+2];


///*****[L,R) format , oot starts with 1*****//

void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = 1;
		return ;
	}
	int mid = (l+r)/2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	T[id] = T[2 * id] + T[2 * id + 1];
}

void update(int p,int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		T[id] = 0;
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
    scani(tc);
    int arr1[200010];

    rep(cs,1,tc)
    {
        scani(n);
        int q;
        scani(q);

        for(int i=1; i<=n ;i++)
        {
            scani(arr1[i]);
        }
         /* for(int i=1; i<=5 ;i++)
                        cout<<arr1[i]<<" ";
                    cout<<endl;*/


        build(1,1,2*100000+1);



        printf("Case %d:\n",cs);
        int temp;
        int curr=n+1;
        int tot=n;

        while(q--)
        {
            char ch;
            getchar();
            scanf("%c %d",&ch,&temp);

            if(ch=='a')
            {
                arr1[curr++]=temp;
                tot++;
            }
            else
            {
                if(temp<=tot)
                {
                    int l=1;
                    int r=2*100000;
                    int mid;

                    while(1)
                    {
                        //cout<<l<<" "<<r<<endl;
                        if(r<=l)
                        {
                            break;
                        }

                        mid=(l+r)/2;

                        int p=ask(1,mid+1,1,0,2*100000+1);

                        //cout<<"left="<<l<<"  right= "<<r<< "mid= "<<mid<<" val="<<p<<endl;

                        if(p<temp)
                        {
                            l=mid+1;
                        }
                        else
                        {
                            r=mid;
                        }
                    }
                   // cout<<l<<endl;
                    printf("%d\n",arr1[l]);

                   /* for(int i=1; i<=5 ;i++)
                        cout<<arr1[i]<<" ";
                    cout<<endl;*/


                    /*cout<<arr1[l]<<endl;*/

                    update(l,1,0,2*100000+1);
                    tot--;

                }
                else
                {
                    printf("none\n");
                }

            }
        }

    }



    return 0;
}

