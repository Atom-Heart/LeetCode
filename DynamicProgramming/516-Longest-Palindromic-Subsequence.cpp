class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        /*dp[i][j]表示s[i - 1, j - 1]回文子串的长度*/
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }

        for(int j = 1; j < n; j++){
            for(int i = j - 1; i >= 0; i--){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else{
                    //取s[i, j - 1] 和 s[i + 1, j]的最大值
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};