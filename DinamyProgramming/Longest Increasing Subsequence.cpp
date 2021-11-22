class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
        vector<int> arr(n);
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int tmp = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    tmp = max(tmp, arr[j]+1);
                }
            }
            
            ans = max(ans, tmp);
            arr[i] = tmp;
        }
        
        return ans;
    }
};