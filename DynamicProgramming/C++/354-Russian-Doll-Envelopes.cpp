class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 0) return 0;
        int n = envelopes.size();
        vector<int> dp(n + 1, 1);
        sort(envelopes.begin(), envelopes.end());
        
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(envelopes[i - 1][0] > envelopes[j - 1][0] && envelopes[i - 1][1] > envelopes[j - 1][1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};