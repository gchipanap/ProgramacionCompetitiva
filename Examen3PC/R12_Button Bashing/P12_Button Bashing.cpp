/*
P12. Button Bashing
https://open.kattis.com/problems/buttonbashing
*/

#include <bits/stdc++.h>

using namespace std;

int main() 
{
  int cases;
  cin >> cases;

  while(cases--) 
  {
    int n, m;
    cin >> n >> m;

    vector<int> move(n);
    for(auto& i : move) 
    {
      cin >> i;
    }

    vector<int> dist(3601, 1e9 + 10);
    dist[0] = 0;

    queue<int> q;
    q.push(0);

    while(!q.empty()) 
    {
      int curr = q.front();
      q.pop();

      for(auto& i : move) 
      {
        int next = curr + i;
        next = max(0,next);
        next = min(3600,next);

        if(dist[next] > dist[curr]+1) {
          dist[next] = dist[curr]+1;
          q.push(next);
        }
      }
    }

    for(int i = m; i <= 3600; i++) 
    {
      if(dist[i] != 1e9 + 10) 
      {
        cout << dist[i] << " " << i - m << endl;
        break;
      }
    }
  }

  return 0;
}