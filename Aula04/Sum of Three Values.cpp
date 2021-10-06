#include <bits/stdc++.h>
#include <iostream>

void search3number(int* arr, int size, int target)
{
  int pos1; int pos2; int pos3;
  for(int i = 0; i < size; i++) 
  {
    int* pointer3 = (arr+i);

    for(int k = 1; k < size ; k++)
    {
      int* pointer2 = (arr+k);

      for(int j = 2; j < size; j++)
      {
        int* pointer1 = (arr+j);
        int sum = *pointer3 + *pointer2 + *pointer1;
        if(sum == target)
        {
          pos1 = i;
          pos2 = k;
          pos3 = j;
        }
      }
    }
  }
  std::cout<<"[ " << pos1+1 << ", " << pos3+1 << ", "<< pos2+1 <<"]";
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

  search3number(arr,size,target);

  return 0;
}