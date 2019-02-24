// A Naive recursive C++ program to find minimum of coins
// to make a given change V
#include<bits/stdc++.h>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{

   if (V == 0) return 0;


   int res = INT_MAX;


   for (int i=0; i<m; i++)
   {
     if (coins[i] <= V)
     {
         int sub_res = minCoins(coins, m, V-coins[i]);


         if (sub_res != INT_MAX && sub_res + 1 < res)
            res = sub_res + 1;
     }
   }
   return res;
}

int main()
{
    int coins[] =  {9, 6, 5, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is "
         << minCoins(coins, m, V);
    return 0;
}
