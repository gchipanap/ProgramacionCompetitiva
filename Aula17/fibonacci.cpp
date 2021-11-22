/*long fib(int n)
{
	if(n <= 1)
		return n;	
	return fib(n-2) + fib(n-1);
}*/

long fib_memoization(int n)
{
	vector<long> memo(n+1);
	return fib(n, memo);	
}

long fib(int n, vector<long> &memo)
{
	if(memo[n])
		return memo[n];
	long result{};
	if(n <= 1)	
		result = n;
	else
		result = fib(n-2, memo) + fib(n-1, memo);
	memo[n] = result;
	return result;
}

long fib_bottomup(int n)
{
	if(n <= 1)
		return n;
	vector<long> F(n+1);
	F[0] = 0;
	F[1] = 1;
	for(int i{2}; i <= n; ++i)
		F[i] = F[i-2] + F[i-1];
	return F[n];
}

