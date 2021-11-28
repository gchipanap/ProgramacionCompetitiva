/*
P3. Rectangle Cutting
https://cses.fi/problemset/task/1744
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  std::cin >> a >> b;
  std::vector<std::vector<int>> dp(a+1,vector<int>(b+1));
  for (int i = 0; i <= a; i++) 
  {
    for (int j = 0; j <= b; j++) 
    {
      if (i == j) 
	      dp[i][j] = 0;
      else 
      {
        dp[i][j] = 1e9;
        for (int k = 1; k < i; k++)
          dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
        for (int k = 1; k < j; k++)
          dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
      }
    }
  }
  std::cout << dp[a][b] << endl;
}