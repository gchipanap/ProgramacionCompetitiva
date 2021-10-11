#include <iostream>
using namespace std;

void p(int* arr, int size)
{
  int arr2[size];
  std::cout<<0<<"\t";
  for(int i = 1; i < size; i++)
  {
    int j = i -1;
    while(arr[j] >= arr[i]&& j>=0)
      j--;
    arr2[i] = j;
    std::cout<<arr2[i]+1<<"\t";
  }
} 

int main()
{
  int size;
  cin>>size;
  int arr[size];
  for(int i = 0 ; i < size; i ++)
    cin>>arr[i];
  p(arr, size);
  return 0;
}