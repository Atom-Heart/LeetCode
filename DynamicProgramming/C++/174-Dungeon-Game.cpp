class Solution {
public:
    /*dp[i][j]表示(i, j)到(m, n)需要的的最小生命值*/
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

        dp[m - 1][n - 1] = dungeon[m - 1][n - 1] >= 0 ? 1 : 1 - dungeon[m - 1][n - 1];
        //cout<<dp[m - 1][n - 1];
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(i == m - 1 && j == n - 1) continue; 
                int x = min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j];
                dp[i][j] = x <= 0 ? 1 : x;
            }
        }
        return dp[0][0];
    }
};