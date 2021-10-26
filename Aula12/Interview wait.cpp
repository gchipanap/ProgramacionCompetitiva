#include<bits/stdc++.h>
using namespace std;

void sol(std::vector<int> t)
{
  std::deque<int> tmp;
  for(auto i : t)
    tmp.push_back(i);
  
  int cont = 0;
  while(!tmp.empty())
  {
    if(tmp.front() == -1 || tmp.back() == -1)
    {
      std::cout<<cont;
      return;
    }
    if(tmp.front() < tmp.back())
    {
      cont += tmp.front();
      tmp.pop_front();
    }
    else
    {
      cont += tmp.back();
      tmp.pop_back();
    }

  }
}

int main()
{
  std::vector<int> t{4,-1,5,2,3};
  sol(t);
}