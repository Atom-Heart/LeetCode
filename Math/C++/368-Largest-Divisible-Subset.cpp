/*暴力回溯*/
class Solution {
public:
    vector<int> ans;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<bool> used(n, false);
        vector<int> route;
        backTracking(nums, 0, route);
        return ans;
    }
    void backTracking(vector<int>& nums, int begin, vector<int>& route){
        if(begin >= nums.size()){
            if(route.size() > ans.size()){
                ans = route;
            }
            return;
        }

        for(int i = begin; i < nums.size(); i++){
            /*路径中一个数字都没有，加入第一个数字*/
            if(route.size() == 0 || nums[i] % route[route.size() - 1] == 0){
                route.push_back(nums[i]);
                backTracking(nums, i + 1, route);
                route.pop_back();
            }
            else{
                backTracking(nums, i + 1, route);
            }
        }
    }
};

/*方法二:DP,但这次的dp返回的是路径，而不是状态*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return nums;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        /*dp[i]存储的是以nums[i]结尾的序列的最大长度*/
        vector<int> dp(n, 1);
        /*pre[i]存储最大序列中nums[i]的上一个元素在nums中出现的下标*/
        vector<int> pre(n, -1);
        /*最大序列长度*/
        int max = 0;
        /*最大序列的最后一个下标*/
        int end = -1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && dp[j] >= dp[i]){
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }

            if(dp[i] > max){
                max = dp[i];
                end = i;
            }
        }

        for(int i = end; i != -1; i = pre[i]){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};