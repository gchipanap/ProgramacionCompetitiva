#include <iostream>
#include <vector>


int sum(std::vector<int> arr, int i, int tam)
{
  int sum = 0;
  for(int j = 0; j < tam; j++)
    sum += arr[i+j];
  return sum;
}

int subarrayMaxTamK(std::vector<int>arr, int tam)
{
  int mayor = 0;
  for(int i = 0; i < tam ; i++)
    mayor += arr[i];

  int posi = 0, posj = tam-1;

  for(int i = 1; i < arr.size()-tam+1; i++)
  {
    if(sum(arr, i, tam) > mayor)
    {
      mayor = sum(arr, i, tam);
    }
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

  int target;
  std::cin>>target;

  int total = subarrayMaxTamK(arr, target);
  
  return 0;
}