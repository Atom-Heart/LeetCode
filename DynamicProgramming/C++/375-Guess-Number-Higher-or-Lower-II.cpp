/*
这道题要明白什么叫最坏情况下的最好情况
最终结果我是要求[1,n]中最坏情况下我需要付出的最小代价，如果我选第i个选错了，那么正确答案肯定在[1,i - 1]或[i + 1, n]中，这两个区间的代价分别为cost1和cost2，我不知道正确区间在哪个，但是我知道我要的是最坏情况，所以我就取最大值。所谓的最好情况就是，在所有这些最坏情况中选择一个最好的，也就是求出这些最坏情况的最小值
*/

/*方法一：记忆化递归*/
class Solution {
public:
    
    
    int helper(int left, int right){
        if(left >= right) return 0;
        int min = INT_MAX;
        for(int i = left; i <= right; i++){
            int res = i + max(helper(left, i - 1), helper(i + 1, right));
            min = ::min(res, min);
        }
        return min;
    }
    int getMoneyAmount(int n) {
        return helper(1, n);
    }
};

/*方法二：DP*/
class Solution {
public:
    int getMoneyAmount(int n) {
        /*取n + 2是为了处理边界问题，当k取到n时，左边区间为[k + 1, right]*/
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        /*遍历所有可能的长度，从2开始取是因为区间的长度最少为2，因为如果是1的话那就直接选，没有代价*/
        /*注意：取len = 1的话就会出现结果错误，为什么？*/
        for(int len = 2; len <= n; len++){
            /*遍历所有的右边界*/
            for(int i = 1; i + len - 1 <= n; i++){
                /*获得左区间*/
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                /*遍历所有可能的取值*/
                for(int k = i; k <= j; k++){
                    dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + k);
                }
            }
        }
        return dp[1][n];
    }
};