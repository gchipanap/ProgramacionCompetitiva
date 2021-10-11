#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int subarrayMax(std::vector<int>arr)
{
  int mayor = arr[0];
  int tmp[arr.size()][arr.size()];
  for(unsigned int i = 0; i < arr.size(); i++)
  {
    for(unsigned int j = 0; j < arr.size()-i; j++)
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
  int  j = 0;
  for(auto i : queries)
  {
    if(i[0] == 1)
      change(arr, i[1], i[2]);
    else if(i[0] == 2)
    {
      results.push_back(maxPrefixSumQuerie(arr,i[1],i[2]));
      std::cout<<results[j]<<"\n";
      j++;
    }
  }
  return results;
}
        
int main() {
  int size, sizeq;
  cin>>size>>sizeq;

  std::vector<int> arr;
  std::vector<std::vector<int>> queries;
  std::vector<int> querie;

  int tmp;
  for(int i = 0; i < size; i++)
  {
    cin>>tmp;
    arr.push_back(tmp);
  }
  for(int i = 0; i < sizeq; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      cin>>tmp;
      querie.push_back(tmp);
    }
    queries.push_back(querie);
    querie.clear();
  }
  std::vector<int> results = PrefixSumQuerie(arr,queries);
}