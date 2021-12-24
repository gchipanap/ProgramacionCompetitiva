/*
P11. Fire
https://open.kattis.com/problems/fire2
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;

bool inrangeguys(int x, int y) 
{
  return x >= 0 && x <= n+1 && y >= 0 && y <= m+1;
}

bool inrangefire(int x, int y) 
{
  return x >= 1 && x <= n && y >= 1 && y <= m;
}

void bfs(vector<vector<char>>& v, queue<pair<int,int>>& oldq, queue<pair<int,int>>& newq, bool fire) 
{
  vector<pair<int,int>> movement = {{1,0},{-1,0},{0,1},{0,-1}};
  while(!oldq.empty()) 
  {
    int currx = oldq.front().first;
    int curry = oldq.front().second;
    oldq.pop();
    for(auto i : movement) 
    {
      int nextx = currx + i.first;
      int nexty = curry + i.second;
      if(fire) 
      {
        if(inrangefire(nextx,nexty)) 
        {
          if(v[nextx][nexty] == '.' || v[nextx][nexty] == '@')
          {
            v[nextx][nexty] = '*';
            newq.push({nextx,nexty});
          }
        }
      }
      else 
      {
        if(inrangeguys(nextx,nexty)) 
        {
          if(v[nextx][nexty] == '.') 
          {
              v[nextx][nexty] = '@';
              newq.push({nextx,nexty});
          }
        }
      }
    }
  }
}

void checkguys(vector<vector<char>>& v, queue<pair<int,int>>& guys) 
{
  queue<pair<int,int>> newguys;
  while(!guys.empty()) 
  {
    pair<int,int> i = guys.front();
    guys.pop();
    if(v[i.first][i.second] != '*') 
    {
      newguys.push(i);
    }
  }
  guys = newguys;
}

void solve() 
{
  cin >> m >> n;

  vector<vector<char>> v;
  v.resize(n+2, vector<char>(m+2, '.'));

  for(int i = 1; i <= n; i++) 
  {
    for(int j = 1; j <= m; j++) 
    {
      cin >> v[i][j];
    }
  }

  queue<pair<int,int>> guys;
  queue<pair<int,int>> fire;

  for(int i = 0; i < n+2; i++) 
  {
    for(int j = 0; j < m+2; j++) 
    {
      if(v[i][j] == '@') 
        guys.push({i,j});
      
      if(v[i][j] == '*')
        fire.push({i,j});
    
    }
  }

  int time = 0;
  bool works = false;
  while(!fire.empty() || !guys.empty()) 
  {
    queue<pair<int,int>> newguys;
    queue<pair<int,int>> newfire;

    bfs(v, guys, newguys, false);
    bfs(v, fire, newfire, true);

    for(int i = 0; i < n+2; i++)
      if(v[i][0] == '@' || v[i][m+1] == '@') works = true;

    for(int j = 0; j < m+2; j++)
      if(v[0][j] == '@' || v[n+1][j] == '@') works = true;

    checkguys(v, newguys);

    guys = newguys;
    fire = newfire;
    time++;

    if(works) break;
  }

  if(works) {
      cout << time << endl;
  }
  else {
      cout << "IMPOSSIBLE" << endl;
  }
}

int main() 
{
  int cases;
  cin >> cases;
  while(cases--) {
      solve();
  }

  return 0;
}