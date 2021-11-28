/*
P4. Elevator Rides
https://cses.fi/problemset/task/1653
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  
  int n, x; 
  std::cin >> n >> x;
  int a[n];

  for (int i = 0; i < n; i++)
      cin>>a[i];

  pair<int, int> dp[1<<n];
  dp[0] = {0, x+1};

  for (int s = 1; s < (1<<n); s++) 
  {
    dp[s] = {25, 0};
    for (int i = 0; i < n; i++) 
    {
      if (s>>i&1)
      {
        auto [c, w] = dp[s^(1<<i)];
        if (w + a[i] > x) 
        {
          c++;
          w = min(a[i], w);
        }
        else
          w += a[i];
        dp[s] = min(dp[s], {c, w});
      }
    }
  }
  std::cout<<dp[(1<<n)-1].first;

}