class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        else if(rowIndex == 1) return {1, 1};
        
        vector<int> dp(rowIndex + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= rowIndex; i++){
            for(int j = i; j >= 0; j--){
                if(j == 0 || j == i) dp[j] = 1;
                else dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp;
    }
};