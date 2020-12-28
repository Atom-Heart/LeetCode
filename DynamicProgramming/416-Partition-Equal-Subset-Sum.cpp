class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums) sum += num;
        if(sum % 2 == 1) return false;
        int target = sum / 2;
        int n = nums.size();
        //vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = target; j >= 1; j--){
                //dp[i][j] = dp[i - 1][j];
                if(j >= nums[i - 1]){
                    dp[j] = (dp[j] || dp[j - nums[i - 1]]);
                }
            }
        }
        return dp[target];
    }
};