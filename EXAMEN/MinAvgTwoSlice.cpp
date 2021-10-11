#include <iostream>
#include <vector>

long long int solution(std::vector<long long> &A)
{
  float min = A[0];
  long long minpos = 0;

  float tmp[A.size()][A.size()];

  for(int i = 0; i < A.size(); i++)
  {
    for(int j = 0; j < A.size()-i; j++)
    {
      if(i == 0)
      {
        tmp[i][j] = A[j];
        std::cout<<tmp[i][j]<<"\t\t";
      }
      else if(i == 1)
      {
        tmp[i][j] = (A[j] + A[j+1])/2.0;
        std::cout<<tmp[i][j]<<"\t\t";
        if(tmp[i][j] < min)
        {
          min = tmp[i][j];
          minpos = j;
        }
      }
      else
      {
        tmp[i][j] = (tmp[i-1][j]*(i) + tmp[0][i+j])/(i+1);
        std::cout<<tmp[i][j]<<"\t\t";
        if(tmp[i][j] < min)
        {
          min = tmp[i][j];
          minpos = j;
        }
      }
    }
    std::cout<<"\n";
  }
  return minpos;
}

int main() {
  std::vector<long long> arr{4,2,2,5,1,5,8};

  long long sol = solution(arr);
  std::cout<<sol;
  return 0;
}