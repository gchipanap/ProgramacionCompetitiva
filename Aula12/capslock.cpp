#include<bits/stdc++.h>
using namespace std;


void sol(std::string t)
{
  std::string tmp;
  bool mayus = 0;
  for(int  i = 0; i < t.length(); i++)
  {
    if(t[i] == '$')
    {
      std::cout<<tmp;
      tmp.clear();
    }
    else if(t[i] == '@')
    {
      mayus = !mayus;
      for(auto &i : tmp)
      {
        if(i <= 90)
          i = i+32;
        if(i >= 97)
          i = i-32;
      }
    }
    else
    {
      if(mayus == 0)
        tmp.push_back(t[i]);
      else
        tmp.push_back(t[i]-32);
    } 
  }
}

int main()
{
  std::string t{"abc$d@ef$@g$"};
  sol(t);
  
  return 0;
}