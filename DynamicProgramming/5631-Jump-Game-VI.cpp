class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        dq.push_back(1);
        for(int i = 2; i <= n; i++){
            if(!dq.empty() && dq.front() < i - k){
                dq.pop_front();
            }
            dp[i] = dp[dq.front()] + nums[i - 1];
            while(!dq.empty() && dp[dq.back()] <= dp[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return dp[n];
    }
};