#include <iostream>

template <typename  T>
bool isIn(T a, T* b, int size)
{
  for(int i = 0; i < size; i++)
  {
    if(b[i] == a)
      return true;
  }
  return false;
}
template <typename  T>
T* ElimDup(T* array, int size)
{
  T* temp = new T[size];
  temp[0] = array[0];
  int iterator = 1;
  for(int i = 1; i < size; i++)
  {
    bool k = isIn<T>(array[i],temp, size);
    if( k == false )
    {
      temp[iterator] = array[i];
      iterator++;
    }
  }
  return temp;
}

int main() {
  int* a = new int[5];
  int temp;
  
  for(int i = 0; i < 5; i++)
  {
    std::cin>>temp;
    a[i] = temp;
  }

  int* b = new int[5];
  b = ElimDup<int>(a, 5);

  int i = 0;
  while(b[i])
  {
    std::cout<<b[i] << " - "; 
    i++;
  }
    
  delete [] a;
  delete [] b;
}
