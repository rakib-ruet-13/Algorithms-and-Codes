/*

 *************************
 Id  : Matrix.code
 Task:
 Date:

 **************************

 */

#include <bits/stdc++.h>
using namespace std;

/*------- Constants---- */

#define Long                    long long
#define ull                     unsigned long long
#define mod                     1000000007
#define MEMSET_INF              63
#define MEM_VAL                 1061109567
#define forn(i,n)               for( int i=0 ; i < n ; i++ )
#define mp(i,j)                 make_pair(i,j)
#define lop(i,a,b)              for( int i = (a) ; i < (b) ; i++)
#define pb(a)                   push_back((a))
#define all(x)                  (x).begin(),(x).end()
#define gc                      getchar_unlocked
#define PI                      acos(-1.0)
#define INF                     1<<29
#define EPS                     1e-9
#define Fr                      first
#define Sc                      second
#define Sz                      size()
#define lc                      ((n)<<1)
#define rc                      ((n)<<1|1)
#define Di(n) scanf("%d",&n);

#define max(a,b)                ((a)>(b) ? (a):(b))
/*---- short Cuts ------- */
#define ms(ara_name,value) memset(ara_name,value,sizeof(ara_name))
typedef pair<int, int> ii;
typedef vector<int > vi ;
typedef vector<Long> vl;
/*------ template functions ------ */
#ifndef getchar_unlocked
#define getchar_unlocked getchar
#endif
template<class T> inline void si(T &x){register int c = gc();x = 0;int neg = 0;for(;((c<48 | c>57) && c != '-');c = gc());
      if(c=='-') {neg=1;c=gc();}for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
template <class T> inline T bigmod(T p,T e,T M){Long ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;} return (T)ret;}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
void io(){freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);}

struct PT {
      int  x,y,id;
      PT(){}
      PT(int _x,int _y){x=_x,y=_y;}
      PT operator + (const PT &p) const { return PT(x+p.x , y + p.y);}
      PT operator - (const PT &p) const { return PT(x-p.x , y - p.y);}
      PT operator * (double c) const { return PT(x*c,y*c);}
      PT operator / (double c) const { return PT(x/c,y/c);}
      void input(){scanf("%d %d",&x,&y);}
};

double dot(PT p,PT q){ return p.x * q.x + p.y * q.y;}
double cross(PT p,PT q) {return p.x*q.y - p.y*q.x;}
double dist2(PT p,PT q) {return dot(p-q , p-q);}
double DIM(PT p) {return sqrt(p.x*p.x+p.y*p.y);}

/*************************** END OF TEMPLATE ****************************/
const int N = 2005;

PT point[N];
PT pivot;
bool cmp(PT a, PT b)
{
      double k = cross(a-pivot,b-pivot);
      if(fabs(k) < EPS) {
            return dist2(a,pivot) < dist2(b,pivot); } else return k > 0;
}
int main()
{
    int t;
      Di(t);
      int cs = 0;
      while(t--){
            int n;
            Di(n);
            forn(i,n){
                  point[i].input();
                  point[i].id = i;
            }
            int iM = point[0].y, id = 0;
            for(int i =1; i < n; i ++ ) {
                  if(point[i].y < iM || (point[i].y == iM && point[i].x < point[id].x)) { id = i; iM = point[i].y; } } swap(point[0] , point[id]); pivot = point[0]; sort(point , point + n , cmp ); int line = 0; for( line = n-2; line > 0 ; line -- ) {
                  double nn = cross(point[n-1] -pivot , point[line] - pivot );
                  if(fabs(nn) > EPS) {
                        break;
                  }
            }
            if(line == 0) printf("Case %d:\nImpossible\n", ++cs);
            else {
                  reverse(point + line+ 1, point + n );
                  printf("Case %d:\n", ++cs);
                  forn(i,n) {if(i) printf(" "); printf("%d", point[i].id);}
                  printf("\n");
            }
      }
      return 0;
}
