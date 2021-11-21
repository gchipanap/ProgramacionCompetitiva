#include <bits/stdc++.h>
using namespace std;

int sol(std::vector <int> &nums , int &k)
{
    int n = nums.size();
    sort(nums.begin() , nums.end());
    return nums[n - k];
}

int main()
{
    vector <int> nums = {3 , 2 , 1 , 5 , 6, 4};
    int k = 2;
    cout << sol(nums , k) << '\n';
}
