#include <iostream>
#include <vector>

int subarrayMax(std::vector<int>arr)
{
  int mayor = arr[0];
  int posi = 0, posj = 0;
  int tmp[arr.size()][arr.size()];
  for(int i = 0; i < arr.size(); i++)
  {
    for(int j = 0; j < arr.size()-i; j++)
    {
      if(i == 0)
      { 
        tmp[i][j] = arr[j];
        if(tmp[i][j] >= mayor)
        {
          mayor = tmp[i][j];
          posi = i; posj = j;
        }
      }
      else
      {
        tmp[i][j] = tmp[i-1][j] + tmp[0][j+i];
        if(tmp[i][j] >= mayor)
        {
          mayor = tmp[i][j];
          posi = i; posj = j;
        }
      }
    }
  }
  std::cout<<"Subarray: ";
  for(int i = 0; i <= posi ; i++)
  {
    std::cout<<arr[i+posj]<<" ";
  } 
  std::cout<<"\n"<<mayor;
  return mayor;
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

  int total = subarrayMax(arr);
  
  return 0;
}