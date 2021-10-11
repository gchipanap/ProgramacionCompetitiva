#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

std::string isPalindrome(vector<std::string> arr, int a, int b)
{
  for (int i = a; i < (b-a)/ 2; i++) {
    if (arr[i] != arr[a + (b-a) - i - 1]) {
      return "NO";
    }
  }
  return "YES";
}

void PalindromeQuerie(vector<std::string>& arr,vector<std::vector<std::string>> queries)
{ 
  int  j = 0;
  for(auto i : queries)
  {
    if(i[0] == "1")
      arr[stoi(i[1])] = i[2];
    else if(i[0] == "2")
    {
      std::cout<<isPalindrome(arr,stoi(i[1]) -1,stoi(i[2])-1)<<"\n";
      j++;
    }
  }
}
        
int main() {
  int size, sizeq;
  cin>>size>>sizeq;

  std::vector<std::string> arr;
  std::vector<std::vector<std::string>> queries;
  std::vector<std::string> querie;

  std::string tmp;
  for(int i = 0; i < size; i++)
  {
    cin>>tmp;
    arr.push_back(tmp);
  }
  for(int i = 0; i < sizeq; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      cin>>tmp;
      querie.push_back(tmp);
    }
    queries.push_back(querie);
    querie.clear();
  }
  PalindromeQuerie(arr,queries);

  return 0;
}