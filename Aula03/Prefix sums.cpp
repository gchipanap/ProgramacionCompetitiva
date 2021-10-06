#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
      
    int n;
    cin >> n;

    int arr[n];
    int cont = 0;
    
    std::cout<<"P_"<<0<<": "<<cont<<"\n";
    for(int i=0; i<n; i++)
    {
      cin >> arr[i];
      cont += arr[i];
      std::cout<<"P_"<<i+1<<": "<<cont<<"\n";
    }
    return 0;
}