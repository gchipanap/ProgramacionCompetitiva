/*
P8. Fibos's Sequence
https://www.beecrowd.com.br/judge/en/problems/view/1701
*/

#include<cstdio>
#include<iostream>

using namespace std;

int grid[1000];

int fibo(int n)
{
  int i =0;
  while(grid[n-i]==0)
    i++;
  for(int j = i; j >= 0; j--)
    grid[n-j] = grid[n-j-1] + grid[n-j-2];
  return grid[n];

}
int fib(int n)
{
  if(n == 1) return grid[1];
  if(n == 0) return 0;
  if(grid[n] != 0) return grid[n];
  else
    return fibo(n);
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  for(int i = 0; i < 1000; i ++) grid[i]=0;
  grid[1] = 1; grid[2] = 1;
  int A, B, N;
  cin>>A>>B>>N;
  while(A!=0 && B!=0 && N!=0)
  {
    int tot = 0;
    for(int i = 0; i < N; i++)
      tot += fib(A+i)*fib(B+i);
    cout<<tot<<'\n';
    cin>>A>>B>>N;
  }
  return 0;
}