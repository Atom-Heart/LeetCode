class Solution {
public:
    bool isMatch(string s, string p) {
        int ls = s.size(), lp = p.size();
        vector<vector<bool>> dp(ls + 1, vector<bool>(lp + 1, false));
        dp[0][0] = true;
        for(int j = 2; j <= lp; j++){
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
        }
        for(int i = 1; i <= ls; i++){
            for(int j = 1; j <= lp; j++){
                int m = i - 1, n = j - 1;
                if(p[n] == '*'){
                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j] && (s[m] == p[n - 1] || p[n - 1] == '.');
                }
                else if(s[m] == p[n] || p[n] == '.'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[ls][lp];
        
    }
};