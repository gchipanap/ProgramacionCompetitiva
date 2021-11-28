/*
P7. Planets and Kingdoms
https://cses.fi/problemset/task/1683
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

std::vector<int> v1[100005], v2[100005];
std::stack<int> stack1;
int grid[100005];

void dfs(int s)
{
  if (grid[s]) 
    return;
  grid[s]=1;
  for (auto i: v1[s]) 
    dfs(i);
  stack1.push(s);
}

int k=0;
void dfs2(int s)
{
  if (grid[s]) return;
  grid[s]=k;
  for (auto i: v2[s]) 
    dfs2(i);
}
void solve(){
  int n,m; 
  std::cin>> n >> m;
  for(int i = 0; i < m; ++i){
    int a,b; 
    std::cin >> a >> b;
    v1[a].push_back(b);
    v2[b].push_back(a);
  }
  for(int i = 1; i < n + 1; ++i) {
    if (!grid[i]) 
      dfs(i);
  }
  memset(grid,0,sizeof grid);
  while(!stack1.empty())
  {
    int x = stack1.top(); stack1.pop();
    if (!grid[x]) 
    {
      k++;
      dfs2(x);
    }
  }
  std::cout<<k<<" "<<std::endl;
  for(int i = 1; i < n+1; ++i)
    std::cout<<grid[i]<<" ";
}    
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

}