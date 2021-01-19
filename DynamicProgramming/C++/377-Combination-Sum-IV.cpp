/*方法一：回溯（超时）*/
class Solution {
public:
    int ans = 0;
    void backTracking(vector<int>& nums, int route, int target){
        if(route == target){
            ans++;
            return;
        }
        for(int i = 0; i < nums.size() && nums[i] + route <= target; i++){
            route += nums[i];
            backTracking(nums, route, target);
            route -=nums[i];
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        backTracking(nums, 0, target);
        return ans;
    }
};

/*方法二：简单递归*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0) return 1;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(target >= nums[i]){
                ans += combinationSum4(nums, target - nums[i]);
            }
        }
        return ans;
    }
};

/*方法三：记忆化搜索*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1);
        memo[0] = 1;
        return DFS(nums, target, memo);
    }
    int DFS(vector<int>& nums, long long target, vector<int>& memo){
        if(memo[target] != -1) return memo[target];

        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(target - nums[i] >= 0){
                res += DFS(nums, target - nums[i], memo);
            }
        }
        memo[target] = res;
        return res;
    }
};
/*方法四：DP*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < target; i++){
            for(int num : nums){
                if(i + num <= target){
                    dp[i + num] += dp[i];
                }
            }
        }
        return dp[target];
    }
};