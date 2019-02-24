
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<bits/stdc++.h>
//#define LLF "%I64u"
#define LLF "%llu"

using namespace std;

int main(void) {
  unsigned long long int a, b, c, x, y, sum, c0;

  cin>>c>>a>>b;
  y = 0;
  sum = a + b;
  c0=c;

  while (c >= sum) { //if c becomes less than a+b, than there's no solution
    c -= b;
    if (c % a == 0) {
      break;
    }
  }
  if (c % a == 0) {
    x = c / a;
    y=(c0-a*x)/b;
    printf("YES\n");
    cout<<x<<" "<<y<<endl;
  } else {
    printf("NO\n");
  }

  return 0;
}
