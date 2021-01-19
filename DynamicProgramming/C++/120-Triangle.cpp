/*滚动数组*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        //vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++){
            dp[i] = triangle[n - 1][i - 1];
        }
        for(int i = n - 1; i >= 1; i--){
            for(int j = 1; j <= i; j++){
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i - 1][j - 1];
            }
        }
        return dp[1];
    }
};