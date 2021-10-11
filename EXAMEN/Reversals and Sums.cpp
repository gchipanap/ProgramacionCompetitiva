#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int sumSubArray(vector<int> arr, int a, int b)
{
  int sum = 0;
  int i = b-a;
  int j;
  if((b-a+1)%2 == 0)
  {
    for(j = a-1; j <= a-1+(b-a)/2; j++)
    {
      sum += arr[j];
      sum += arr[j+i];
      i -= 2;
    }
  }
  else
  {
    for(j = a-1; j < a-1+(b-a)/2; j++)
  {
    sum += arr[j];
    sum += arr[j+i];
    i -= 2;
  }
  sum+=arr[j];
  }
  return sum;
}

void reverse(vector<int>& arr, int a, int b)
{
  int i = b-a;
  int j;
  int tmp;
  for(j = a-1; j < a-1+(b-a)/2; j++)
  {
    tmp = arr[j];
    arr[j] = arr[j+i];
    arr[j+i] = tmp;
    i -= 2;
  }
    tmp = arr[j];
    arr[j] = arr[j+i];
    arr[j+i] = tmp;
}

void PalindromeQuerie(vector<int>& arr,vector<std::vector<int>> queries)
{ 
  int  j = 0;
  for(auto i : queries)
  {
    if(i[0] == 1)
    {
      reverse(arr, i[1], i[2]);
    }
      
    else if(i[0] == 2)
    {
      std::cout<<sumSubArray(arr, i[1], i[2])<<"\n";
      j++;
    }
  }
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
 PalindromeQuerie(arr,queries);

  return 0;
}