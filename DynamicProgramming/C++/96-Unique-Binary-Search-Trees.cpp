/*如果n = 2，那么只有两种，一种是1当根节点，一种是2当根节点*/
/*如果n = 3，当1为根节点时：左子树为空，右子树为2和3组成的子BST；当2为根节点时，左子树为1，右子树为3；当3为根节点时，左子树为1和2组成的子BST，右子树为空*/
/*这个时候要注意的是：2和3组成的BST的种类和1和2组成的BST种类是一样的，取决于参与构建的个数，因为都是两个连续递增的数，属于相同的子问题*/
/*所以当数字i为根节点时，左子树BST用j个节点，右子树BST用i - j - 1个节点，能构建出dp[j] * dp[i - j - 1]中不同的BST， 0 <= j <= i - 1;*/
/*dp(i)=∑dp(j)∗dp(i−j−1),0<=j<=i−1*/


/*动态规划（从底向上）*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;//空树
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j <= i - 1; j++){
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};


/*记忆化递归(自顶向下)*/
class Solution {

public:
    int dp(int n, vector<int>& memo){
        if(n == 0 || n == 1) {
            memo[n] = 1;
            return memo[n];
        }
        if(memo[n] != 0) return memo[n];
        for(int i = 0; i <= n - 1; i++){
            memo[n] += dp(i, memo) * dp(n - i - 1, memo);
        }
        return memo[n];
    }
    int numTrees(int n) {
        vector<int> memo(n + 1, 0);
        return dp(n, memo);
    }
};