class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0x3f3f3f3f));
        //for(int i = 0; i <= n; i++) dp[i][0] = 0;
        vector<int> dp(amount + 1);
        for(int i = 0; i <= amount; i++) dp[i] = 0x3f3f3f3f;
        dp[0] = 0;
        
        /*dp[i][j] = dp[i - 1][j], dp[i - 1][j - c] + 1, dp[i - 1][j - 2c] + 2, ....., dp[i - 1][j - k * c] + k * c*/
        /*dp[i][j - c]             dp[i - 1][j - c],     dp[i - 1][j - 2c] + 2, ....., dp[i - 1][j = k * c] + (k - 1) * c*/
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                if(j - coins[i - 1] >= 0){
                    dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
                }
            }
        }
        return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
    }
};