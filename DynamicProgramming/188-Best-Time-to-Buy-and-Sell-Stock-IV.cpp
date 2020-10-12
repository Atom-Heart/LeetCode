class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 0) return 0;
        /*如果交易的次数大于价格数目的一半，那么就说明可以每天都尝试交易，然后第二天再卖掉*/
        if(k > prices.size() / 2){
            int sum = 0;
            for(int i = 0; i < prices.size() - 1; i++){
                if(prices[i] < prices[i + 1]) sum += (prices[i + 1] - prices[i]);
            }
            return sum;
        }
		int size = prices.size();
		vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
		for (int i = 0; i <= prices.size(); i++) {
			dp[i][0][1] = INT_MIN;//Base case
		}
		for (int i = 0; i <= k; i++) {
			dp[0][i][1] = INT_MIN;
		}

		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= k; j++) {
				dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i - 1]);
				dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i - 1]);
			}
		}
		return dp[size][k][0];
	}
};