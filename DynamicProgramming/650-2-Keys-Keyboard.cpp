class Solution {
public:
    /*阶段：n阶问题，每阶有j个子问题，即可以在已赋值j个的基础上粘贴*/
    /*状态：粘贴之前必须复制（限定条件），复制有j个A，当前有i个A*/
    /*状态转移方程：dp[i][j] = min(dp[i - j][j] + 1, dp[i][j])*/
    int minSteps(int n) {
        if(n == 0) return 0;
        vector<vector<int>> dp(n + 1);
        for(int i = 0; i <= n; i++){
            dp[i].resize(n + 1, n);
        }
        dp[1][1] = 0;//初始状态
        for(int i = 1; i <= n; i++){
            int minNum = dp[i][1];
            for(int j = 1; j <= i; j++){
                if(i - j >= 1){
                    dp[i][j] = min(dp[i - j][j] + 1, dp[i][j]);//i个A，要在i-j的基础上粘贴j个A
                    minNum = min(minNum, dp[i][j]);
                }
                if(i == j) dp[i][j] = minNum + 1;//当i == j的时候，表示复制的所有'A'肯定是在最小操作数的基础上复制，所以要记录最小值
            }
        }
        return dp[n][n] - 1;
    }
};