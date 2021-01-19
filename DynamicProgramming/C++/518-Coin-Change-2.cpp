class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        //vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        //二维：dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]]
        for(int i = 1; i <= n; i++){
            for(int j = coins[i - 1]; j <= amount; j++){
                dp[j] += dp[j - coins[i - 1]];
            }
        }
        return dp[amount];
    }
};