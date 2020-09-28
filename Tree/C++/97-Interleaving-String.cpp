class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        if(m + n != s3.size()) return false;
        dp[0][0] = true;
        for(int i = 1; i <= m; i++){
            if(s3[i - 1] == s1[i - 1]){
                dp[i][0] = true;
            }
            else{
                break;
            }
        }

        for(int i = 1; i <= n; i++){
            if(s3[i - 1] == s2[i - 1]){
                dp[0][i] = true;
            }
            else{
                break;
            }
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = (dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]) || (dp[i][j - 1] && s3[i + j - 1] == s2[j - 1]);
            }
        }
        return dp[m][n];
    }
};