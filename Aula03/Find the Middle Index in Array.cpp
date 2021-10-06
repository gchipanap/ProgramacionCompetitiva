#include <bits/stdc++.h>
using namespace std;
  
int find_midle(std::vector<int> arr)
{
  int sum = 0, psum=0;
  for (int x : arr) sum += x;
  for (int i=0; i<arr.size(); i++) 
  {
    if (psum==sum-psum-arr[i]) 
    return i;
    psum += arr[i];
  }
  return -1;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);   
    
  int n;
  cin >> n;

  std::vector<int> arr;
  int tmp;

  for(int i=0; i<n; i++)
  {
    cin >> tmp;
    arr.push_back(tmp);
  }

  int midle = find_midle(arr);
  cout<<midle;
  return 0;
}