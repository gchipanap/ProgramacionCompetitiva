#include <bits/stdc++.h>
#include <deque>
using namespace std;

void sol(std::string s)
{
std::deque<char> d;
for(int i = 0; i < s.length(); i++)
  {
    if(s[i] == '#')
      d.pop_back();
    else 
      d.push_back(s[i]);
  }

  while(!d.empty())
  {
    std::cout<<d.front();
    d.pop_front();
  }
}

int main()
{
  std::string s{"abc#de##f#ghi#jklmn#op#"};
  
  sol(s);
  
  return 0;
}