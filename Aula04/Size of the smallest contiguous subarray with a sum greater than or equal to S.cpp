#include <iostream>
#include <vector>

int subarraySumSmall(std::vector<int>arr, int target)
{
  int tmp[arr.size()][arr.size()];
  for(int i = 0; i < arr.size(); i++)
  {
    for(int j = 0; j < arr.size()-i; j++)
    {
      if(i == 0)
      { 
        tmp[i][j] = arr[j];
        if(tmp[i][j] >= target)
        {
          std::cout<<i+1;
          return i;
        }
      }
      else
      {
        tmp[i][j] = tmp[i-1][j] + tmp[0][j+i];
        if(tmp[i][j] >= target)
        {
          std::cout<<"\n"<<i+1;
          return i+1;
        }
      }
    }
  }
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
  std::cout<<"S: "; std::cin>>target;
  int total = subarraySumSmall(arr,target);
  
  return 0;
}