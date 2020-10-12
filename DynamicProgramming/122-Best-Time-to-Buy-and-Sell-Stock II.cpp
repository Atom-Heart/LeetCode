/*方法一：贪心*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int ans = 0;
        for(int i =  0; i < prices.size() - 1; i++){
            if(prices[i] < prices[i + 1]){
                ans += prices[i + 1] - prices[i];
            }
        }
        return ans;
    }
};

/*方法二：DP*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        dp[0][1] = INT_MIN;
        for(int i = 1; i <= prices.size(); i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
        }
        return dp[prices.size()][0];
    }
};