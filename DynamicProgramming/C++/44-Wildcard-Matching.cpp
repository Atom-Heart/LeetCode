class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        /*初始化*/
        dp[0][0] = true;
        /*p开头如果是连续的* ，那就都要初始化成True，表示可以匹配空串*/
        for(int i = 1; i <= n; i++){
            if(p[i - 1] != '*'){
                break;
            }
            dp[0][i] = true;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '*'){
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};