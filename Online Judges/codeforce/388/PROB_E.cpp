#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn = 1e7+7;
int n,k;
ll f[maxn],sum[maxn];
void init() {
  for(int i=maxn-1;i>=2;i--) {
    if (f[i]) {
      if (i%2==0)  f[i/2] +=  f[i] * 2;
      else {
        f[i/2] += f[i]; f[i/2+1] +=f[i];
      }
    }
  }
  for(int i=1;i<maxn;i++) {
    sum[i] = sum[i-1] + f[i];
  }
  ll t;
  for(int i=maxn-1; i>=2 ;i--) N{
    if ((i-1)*2 >=maxn) t = sum[maxn-1] - sum[i-1];
    else t = sum[(i-1)*2] - sum[i-1];
    if (t>=k) {
      printf("%d\n",i);
      exit(0);
    }
  }
  if (f[1] >=k) {
    printf("1");
    exit(0);
  }
}
int main() {
  #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
  #endif
  scanf("%d %d", &n, &k);

  For(i,1,n) {
    int x;
    scanf("%d", &x);
    f[x] ++;
  }
  int t = 0;
  init();
  printf("-1");
}
