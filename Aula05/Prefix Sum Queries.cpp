#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int subarrayMax(std::vector<int>arr)
{
  int mayor = arr[0];
  int tmp[arr.size()][arr.size()];
  for(int i = 0; i < arr.size(); i++)
  {
    for(int j = 0; j < arr.size()-i; j++)
    {
      if(i == 0)
      { 
        tmp[i][j] = arr[j];
        if(tmp[i][j] >= mayor)
          mayor = tmp[i][j];
      }
      else
      {
        tmp[i][j] = tmp[i-1][j] + tmp[0][j+i];
        if(tmp[i][j] >= mayor)
          mayor = tmp[i][j];
      }
    }
  } 
  if(mayor < 0) return 0;
  return mayor;
}

int maxPrefixSumQuerie(vector<int> arr, int a, int b)
{
  vector<int> tmp;
  for(int i = a-1; i <= b-1; i++)
    tmp.push_back(arr[i]); 
  return subarrayMax(tmp);
}

void change(vector<int>& arr, int k, int u)
{
  arr[k-1] = u;
}

vector<int> PrefixSumQuerie(vector<int>& arr,vector<std::vector<int>> queries)
{ 
  vector<int> results;
  for(auto i : queries)
  {
    if(i[0] == 1)
      change(arr, i[1], i[2]);
    else if(i[0] == 2)
    {
      results.push_back(maxPrefixSumQuerie(arr,i[1],i[2]));
    }
  }
  return results;
}
        
int main() {
  std::vector<int> arr{1, 2, -1, 3, 1, -5, 1, 4};
  std::vector<std::vector<int>> queries{{2, 2, 6},{1, 4, -2},{2, 2, 6},{2, 3, 4}};
  
  std::vector<int> results = PrefixSumQuerie(arr,queries);

  for(auto i : results) cout<<i<<"\n";
}