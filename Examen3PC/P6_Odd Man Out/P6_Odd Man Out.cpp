/*
P6. Odd Man Out
https://open.kattis.com/problems/oddmanout
*/

 #include <iostream>
#include <map>
#include <unordered_map>

int main() {
  int n;
  std::cin>>n;
  int a,b,c,y,z;
  for(int i = 0 ; i < n; i++)
  {
    std::unordered_map<int, int> odds;
    z = 0;
    std::cin>>y;
    while (z < y) 
    {
      std::cin>>a;
      odds[a]++;
      z++;
    }
    std::cout << "Case #" << i + 1 << ": ";
    for(auto a : odds){
        if (a.second == 1) {
          std::cout << a.first << std::endl;
        }
    }
  }
  return 0;
} 
