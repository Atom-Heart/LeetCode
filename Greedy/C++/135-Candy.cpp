class Solution {
public:
    vector<int> dp;
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        dp.resize(n, -1);
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += dfs(ratings, i);
        }
        return ans;
    }

    int dfs(vector<int> &ratings, int idx){
        if(dp[idx] != -1) return dp[idx];
        dp[idx] = 1;
        
        if(idx > 0 && ratings[idx] > ratings[idx - 1]) dp[idx] = max(dp[idx], dfs(ratings, idx - 1) + 1);
        if(idx < ratings.size() - 1 && ratings[idx] > ratings[idx + 1]) dp[idx] = max(dp[idx], dfs(ratings, idx + 1) + 1);

        return dp[idx];
    }

};

