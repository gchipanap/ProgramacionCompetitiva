#include <iostream>
#include <cmath>

void order(int*& a, int size)
{
  int* temp = new int [size];
  for(int i = 0; i < size; i++)
  {
    temp[i] = a[size-i-1];
  }
  a = temp;
  delete [] temp;
}
int* sum(int * a, int* b, int size)
{
  int* temp = new int [size];
  int lleva = 0;
  for(int i = 0; i < size; i++)
  {
    temp[size-i-1] = a[i] + b[i] + lleva;
    if(a[i] + b[i] + lleva > 9)
    {
      temp[size-i-1] = temp[size-i-1] % 10;
      lleva = 1;
    }
    else 
      lleva = 0;
  }
  return temp;
}



int main() {
  int size;
  std::cout<<"Tam ";
  std::cin>>size;
  int* a = new int [size];
  int* b = new int [size];
  int temp;
  std::cout<<"Primer Numero: (";
  for(int i = 0 ; i < size; i++)
  {  
    std::cin>>temp;
    a[i] = temp;
    std::cout<<" -> ";
  }
  std::cout<<"Segundo Numero: (";
  for(int i = 0 ; i < size; i++)
  {
    std::cin>>temp;
    b[i] = temp;
    std::cout<<" -> ";
  }

  int* suma = new int [size];
  suma = sum(a, b, size);

  std::cout<<"Respuesta: (";
  for(int i = 0 ; i < size ; i++)
  {
    std::cout<<suma[i] << "->";
  }
  std::cout<<")";
}