#include<bits/stdc++.h>
using namespace std;


void  sol(std::vector<std::vector<int>> t)
{
  std::vector<int> tmp;

  for(auto i : t)
    for(auto j : i)
      tmp.push_back(j);

  std::priority_queue<int, std::vector<int>,std::greater<int>> s(tmp.begin(), tmp.end());
  
  for (; !s.empty(); s.pop())
  {
      std::cout << s.top() << ' ';
  }
}


int main()
{
  std::vector<std::vector<int>> t{{1,4,5},{1,3,4},{2,6}};
  sol(t);
  
  return 0;
}