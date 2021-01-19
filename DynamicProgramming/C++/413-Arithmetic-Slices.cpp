/*方法一：数学，利用差分数组*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0;
        /*计算差分数组*/
        for(int i = A.size() - 1; i >= 1; i--){
            A[i] = A[i] - A[i - 1];
        }
        /*寻找最长连续相等区间，如果这个连续区间的长度为k，那么代表有长度为k + 1的等差数列，然后再求出等差数列有多少个子数列*/
        /*由于题目要求最短的等差数列长度为3，那么一共有(k+1)-2 + (k + 1) - 3 + **** + 1 = k * (k - 1) / 2个子等差数列 */
        for(int i = 1; i < A.size(); i++){
            int j = i + 1;
            while(j < A.size() && A[j] == A[i]) j++;
            int len = j - i;
            ans += len * (len - 1) / 2;
            i = j - 1;
        }
        return ans;
        
    }
};
方法二：DP
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = A[2] - A[1] == A[1] - A[0] ? 1 : 0;
        for(int i = 3; i < A.size(); i++){
            dp[i] = (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) ? dp[i - 1] + 1 : 0;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += dp[i];
        }
        return ans;
    }
};