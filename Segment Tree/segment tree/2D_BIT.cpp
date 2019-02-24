#include<iostream>
#include<bits/stdc++.h>

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

using namespace std;

int max_x,max_y;
int  max_val; /****** The size of array******/

int tree[1030][1030];
int T[100010];


/***2D BIT***/

void updatex(int x , int y , int val);
void updatey(int x , int y , int val);
void update_xy(int x , int y , int val);
int readx(int x,int y);
int ready(int x,int y);

void updatex(int x , int y , int val){
    while (x <= max_x){
        updatey(x , y , val);
        // this function should update array tree[x]
        x += (x & -x);
    }
}

void updatey(int x , int y , int val){
    while (y <= max_y){
        tree[x][y] += val;
        y += (y & -y);
    }
}

void update_xy(int x , int y , int val){
    int y1;
    while (x <= max_x){
        y1 = y;
        while (y1 <= max_y){
            tree[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

int readx(int x,int y){
    int sum = 0;
    while ( x > 0){
        sum +=ready(x,y);
        x -= (x & -x);
    }
    return sum;
}

int ready(int x,int y){
    int sum = 0;
    while ( y > 0){
        sum +=tree[x][y];
        y -= (y & -y);
    }
    return sum;
}


/******1D BIT sum sub array****/
int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += T[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx ,int val){
    while (idx <= max_val){
        T[idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{




    return 0;
}


