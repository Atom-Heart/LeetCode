class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum < S || -sum > S) return 0;
        
        int n = nums.size();
        /*数的区间是[-sum, sum]，但下标不能表示负数，所以需要引入一个偏移量，将负数用正数表示*/
        /*变换后的范围是[0, 2 * sum]，其中[0, sum]表示[-sum, 0]*/
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));
        dp[0][0 + sum] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = -sum; j <= sum; j++){
                if(j - nums[i - 1] >= -sum) dp[i][j + sum] += dp[i - 1][j - nums[i - 1] + sum];
                if(j + nums[i - 1] <= sum) dp[i][j + sum] += dp[i - 1][j + nums[i - 1] + sum];
            }
        }
        return dp[n][S + sum];

    }
};