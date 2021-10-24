#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k,A,B;
  std::cin>>k;
  std::cin>>n; 

  vector<int> instructions(n,0);
  vector<int> tmp(n,0);

  for(int i=0; i<k; i++)
  {
    std::cin>>A>>B;
    instructions[A-1] += 1;
    instructions[B]-= 1;
	}
	tmp[0] = instructions[0];

	for(int i=1; i<n; i++)
		tmp[i] = tmp[i-1]+instructions[i];

  sort(tmp.begin(), tmp.end());
    
  if(n%2 != 0)
    std::cout<<tmp[tmp.size()/2];
  else
    std::cout<<(tmp[tmp.size()/2]+tmp[tmp.size()/2-1])/2.0;

	return 0;
}