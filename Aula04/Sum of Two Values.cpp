#include <bits/stdc++.h>
#include <iostream>

void search2number(int* arr, int size, int target)
{
  int pos1; int pos2;
  for(int i = 0; i < size; i++) //pointer2
  {
    int* pointer2 = (arr+i);
    for(int j = 1; j < size; j++) // pointer1
    {
      int* pointer1 = (arr+j);
      int sum = *pointer1 + *pointer2;
      if(sum == target)
      {
        pos1 = i;
        pos2 = j;
      }
      sum = 0;
    }
  }
  std::cout<<"[ " << pos2+1 << ", " << pos1+1 << "]";
}

int main() {
  int size;
  std::cin>>size;
  int arr[size];
  for(int i = 0; i < size; i++)
  {
    std::cout<<"arr[" << i <<"]: ";
    std::cin>> arr[i];
    std::cout<<std::endl;
  }

  int target;
  std::cin>>target;

  search2number(arr,size,target);

  return 0;
}