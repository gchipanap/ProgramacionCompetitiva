#include <bits/stdc++.h>
using namespace std;


int ddowntime(std::map<int, int>& mp , int k)
{
  int acum=0 ,i=0 ;
  double value;
  vector <int> vec(mp.size(),0);

  for (auto itr = mp.begin(); itr != mp.end(); itr++)
  {
    acum+= itr->second;
    vec[i]=acum;
    i++;
  }

  sort(vec.begin(), vec.end()); 
  value = vec[ vec.size()-1];
  
  return ceil(value/k);
    

}

int main()
{
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  int n, k;
  int A;
  
  std::map<int, int> tmp;

  std::cin>>n>>k;

  for(int i=0;i<n;i++)
  {     
    cin >> A ;
    tmp[A]++;
    tmp[A+1000]--;
  }

  cout << ddowntime( tmp , k);

    return 0;
}