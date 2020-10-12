/*方法一：空间换时间，保存每个位置之前的最小值*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<int> dp(prices.size(), 0);
        dp[0] = prices[0];
        for(int i = 1; i < prices.size(); i++){
            dp[i] = min(prices[i], dp[i - 1]);
        }
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            int num = prices[i] - dp[i];
            if(num > profit) profit = num;
        }
        return profit;
    }
};
/*方法二：单调递减栈法*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int ans = 0;
        stack<int> min_stack;
        min_stack.push(prices[0]);
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < min_stack.top()){
                min_stack.push(prices[i]);
            }
            else{
                ans = max(ans, prices[i] - min_stack.top());
            }
        }
        return ans;
    }
};
/*方法三:DP*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        dp[0][1] = INT_MIN;
        for(int i = 1; i <= prices.size(); i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], -prices[i - 1]);
        }
        return dp[prices.size()][0];
    }
};