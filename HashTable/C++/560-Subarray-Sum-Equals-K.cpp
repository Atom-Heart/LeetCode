class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*前缀和 ： 出现次数*/
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        mp[0] = 1;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            preSum[i] = preSum[i - 1] + nums[i - 1];
            int x = preSum[i] - k;
            if(mp.find(x) != mp.end()) ans += mp[x];
            mp[preSum[i]]++;
        }
        return ans;
    }
};