/*
P10. Golnaldinho
https://www.beecrowd.com.br/judge/en/problems/view/2792
*/

#include <iostream>
#include <vector>

using namespace std;

#define INT_MAX 500005

int conv(int n){
	return n & (-n);
}

void act_vector(std::vector<int> &v1, int node, int v)
{
	while(node < INT_MAX)
	{
		v1[node] += v;
		node += conv(node);
	}
}

int gonaldinho(std::vector<int> &v1, int node){
	int sum = 0;
	while(node > 0)
	{
		sum = sum + v1[node];
		node = node - conv(node);
	}
	return sum;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	int K, N, ik;
	std::cin >> N;
	std::vector<int> v1(INT_MAX, 0);
	for(K = 1; K <= N; K++){
		std::cin >> ik;
		std::cout << (ik - gonaldinho(v1, ik));
		if(K == N)
			std::cout << endl;
		else
			std::cout << " ";
		act_vector(v1, ik, 1);
	}
	return 0;
}