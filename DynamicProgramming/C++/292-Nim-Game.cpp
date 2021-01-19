class Solution {
public:
    bool canWinNim(int n) {
        /*方法一：数学方法*/
        /*return n % 4 != 0;*/
    }
};

/*方法二：记忆化递归(超时)*/

class Solution {
public:
    int dfs(int n, vector<int>& dp){
        if(n == 1 || n == 2 || n == 3) return 1;
        else if(n == 0) return -1;
        
        if(dp[n] == -1){
            dp[n] = !(dfs(n - 1, dp) & dfs(n - 2, dp) & dfs(n - 3, dp));
        }
        return dp[n];

    }
    bool canWinNim(int n) {
        if(n == 1 || n == 2 || n == 3) return true;
        else if(n == 0) return false;
        vector<int> dp(n + 1, -1);
        /*base case*/
        dp[0] = -1;
        dp[1] = dp[2] = dp[3] = 1;
        
        int ans = dfs(n, dp);
        if(ans == 1) return true;
        else return false;
        
    }
};

/*方法三：记忆化递归（超时）*/
class Solution {
public:
    bool canWinNim(int n) {
        vector<bool> dp(n + 1);
        dp[0] = false;
        dp[1] = dp[2] = dp[3] = true;

        for(int i = 4; i <= n; i++){
            dp[i] = !(dp[i - 1] && dp[i - 2] && dp[i - 3]);
        }
        return dp[n];
    }
};
