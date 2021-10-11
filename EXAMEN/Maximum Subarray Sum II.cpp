#include <iostream>
#include <vector>

int32_t sum(std::vector<int32_t> arr, int i, int tam)
{
  long long int sum = 0;
  for(int j = 0; j < tam; j++)
    sum += arr[i+j];
  return sum;
}

int32_t subarrayMax(std::vector<int32_t>arr, int a, int b)
{
  int32_t mayor = arr[a-1];
  int32_t tmp[b-a+2][arr.size()];

  if (a == 1)
  {
    for(int i = 0; i < arr.size(); i++)
    {
      tmp[0][i] = arr[i];
      if(tmp[0][i] > mayor)
        mayor = tmp[0][i];
    }
  }
  else 
  {
    for(int i = 0; i < arr.size(); i++)
      tmp[0][i] = arr[i];
  }

  for(int i = 0; i < arr.size()-a+1; i++)
  {
    tmp[1][i] = sum(arr, i, a);
    if(tmp[1][i] >= mayor)
      mayor = tmp[1][i];
  }

  for(int i = 2; i < b-a+2; i++)
  {
    for(int j = 0; j < arr.size()-a-i+2; j++)
    {
      tmp[i][j] = tmp[i-1][j] + tmp[0][a+j+i-2];
      if(tmp[i][j] >= mayor)
        mayor = tmp[i][j];
    }
  }
  return mayor;
}

int main() {
  int size, tam1, tam2;
  std::vector<int32_t> arr;

  std::cin>>size>>tam1>>tam2;
  int32_t tmp;

  for(int i = 0; i < size; i++)
  {
    std::cin>>tmp;
    arr.push_back(tmp);
  }

  //std::vector<int> arr{-22, 0, 78, -48, 94, 68, -7, -73, 8, 62};
  int32_t total = subarrayMax(arr, tam1, tam2);
  std::cout<<total;
  return 0;
}