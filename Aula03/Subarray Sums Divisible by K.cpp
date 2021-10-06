#include <iostream>
#include <vector>

int subarraysDivByK(std::vector<int>arr, int divisible)
{
  int cont = 0;
  int tmp[arr.size()][arr.size()];
  for(int i = 0; i < arr.size(); i++)
  {
    for(int j = 0; j < arr.size(); j++)
    {
      if(i == 0)
      { 
        tmp[i][j] = arr[j];
        if(arr[i] % divisible == 0)
          cont++;
      }
      else
      {
        tmp[i][j] = tmp[i-1][j] + tmp[0][j+i];
        if(tmp[i][j] % divisible == 0)
          cont++;
      }
    }
  }
  std::cout<<"Total: " << cont/2;
  return cont/2;
}

int main() {
  int size;
  std::cin>>size;

  int tmp;
  std::vector<int> arr;
  for(int i = 0; i < size; i++)
  {
    std::cout<<"arr[" << i <<"]: ";
    std::cin>> tmp;
    arr.push_back(tmp);
    tmp = 0;
    std::cout<<std::endl;
  }

  int target;
  std::cin>>target;

  int total = subarraysDivByK(arr, target);
  
  return 0;
}