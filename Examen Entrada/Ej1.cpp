#include <iostream>
#include <string>
//Ejercicio 1

bool isInString(char i, std::string b)
{
  for(const auto j : b)
    if(i == j)
      return true;
  return false;
}
bool isAnagramD(std::string a, std::string b)
{	
  bool isIn;
  if(a.size() != b.size())
    return false;
	for(const auto i : a)
  {
    if(isInString(i,b))
      continue;
    else
      return false;
  }
  return true;
}
bool IsAnagram(std::string a, std::string b)
{
  bool correct1 = isAnagramD(a,b);
  bool correct2 = isAnagramD(b,a);
  if(correct1 & correct2)
    return true;
  else
    return false;
}
int main()
{
  std::string a = "roaa";
  std::string b = "mora";
  bool i = IsAnagram(a,b);
  if(i)
    std::cout<<"Si es";
  else 
    std::cout<<"No es";
}
