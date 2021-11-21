#include <unordered_set>
#include <stack>
#include <cstdio>

class Sky {
public:
    Sky(int m, int n)
    {
	for (int i = 0; i < this->m; i++) 
	{
        char buffer[this->n + 1];
        scanf("%s", buffer);
        for (int j = 0; j < this->n; j++) 
	{
            if (buffer[j] == '-') {
                stars.insert(i * this->n + j);
            }
        }
    	}
    }
    int number_of_stars()
    {
	 int counter = 0;
    while (!stars.empty()) {
        std::stack<int> connected;
        connected.push(*stars.begin());
        while (!connected.empty()) {
            int current = connected.top();
            connected.pop();
            if (stars.erase(current)) {
                int neighbor, mod;
                if (stars.find(neighbor = current - n) != stars.end()) connected.push(neighbor);
                if (stars.find(neighbor = current + n) != stars.end()) connected.push(neighbor);
                if ((mod = current % n) > 0 && stars.find(neighbor = current - 1) != stars.end()) connected.push(neighbor);
                if (mod < n - 1 && stars.find(neighbor = current + 1) != stars.end()) connected.push(neighbor);
            }
        }
        counter++;
    }
    return counter;
    }
private:
    int n, m;
    std::unordered_set<int> stars;
};

int main() {
    int m, n, test_case = 1;
    while (scanf("%d %d", &m, &n) == 2) {
        printf("Case %d: %d\n", test_case++, Sky(m,n).number_of_stars());
    }
    return 0;
}
