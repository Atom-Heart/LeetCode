class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        int i = 1;
        for(auto item : strs){
            int x = 0, y = 0;
            for(int j = 0; j < item.size(); j++){
                if(item[j] == '0') x++;
                else y++;
            }

            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    dp[i][j][k] = dp[i - 1][j][k];
                    if(j >= x && k >= y){
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - x][k - y] + 1);
                    }
                }
            }
            i++;
        }
        return dp[len][m][n];
    }
};