//Suma de prefijos
#include <iostream>

int main() {
  int size, sumTot;
  std::cin>>size;
  int arr[size];
  for(int i = 0; i < size; i++)
  {
    std::cout<<"arr[" << i <<"]";
    std::cin>> arr[i];
    std::cout<<std::endl;
  }
  sumTot = arr[0];
  std::cout<<sumTot << std::endl;
  for(int i = 1; i < size; i++)
  {
    sumTot = sumTot + arr[i];
    std::cout<< sumTot << std::endl;
  }
}