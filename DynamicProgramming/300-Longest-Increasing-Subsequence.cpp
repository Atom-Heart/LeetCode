class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp(n + 1, 1);
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(nums[i - 1] > nums[j - 1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};