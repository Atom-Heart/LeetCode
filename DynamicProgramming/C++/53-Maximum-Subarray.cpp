class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++){
            dp[i] = max(nums[i - 1], nums[i - 1] + dp[i - 1]);
        }
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};