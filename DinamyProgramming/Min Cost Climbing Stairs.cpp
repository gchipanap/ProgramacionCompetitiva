class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> arr(n + 1, 0);
        for (int i = 2; i < n + 1; ++i) {
            arr[i] = min(arr[i- 2] + cost[i - 2], arr[i - 1] + cost[i - 1]);
        }
        return arr.back();
    }
};