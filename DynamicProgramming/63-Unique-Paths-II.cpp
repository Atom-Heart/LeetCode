class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= m; i++) {
            if(obstacleGrid[i - 1][0] == 0) dp[i][1] = 1;
            else break;
        }

        for(int j = 1; j <= n; j++) {
            if(obstacleGrid[0][j - 1] == 0) dp[1][j] = 1;
            else break;
        }


        for(int i = 2; i <= m; i++){
            for(int j = 2; j <= n; j++){
                if(obstacleGrid[i - 1][j - 1] != 1){
                    int up = 0, left = 0;
                    left = obstacleGrid[i - 1][j - 2] == 1 ? 0 : dp[i][j - 1];
                    up = obstacleGrid[i - 2][j - 1] == 1 ? 0 : dp[i - 1][j];
                    dp[i][j] = left + up;
                }
            }
        }

        return dp[m][n];
    }
};