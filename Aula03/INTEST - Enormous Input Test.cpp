#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
      
    int n, target, entrada;
    int cont = 0;
    cin >> n >> target;
    for (int i=0; i<n; i++)
    {
      cin >> entrada;
      if (entrada % target == 0)
        cont++;
    }
    cout << cont << "\n";
    return 0;
}