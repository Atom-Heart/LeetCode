class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        /*构造前缀和数组*/
        for(int i = 1; i <= n; i++){
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }

        /*如果存在连续的两个0，那就可以*/
        if(k == 0){
            for(int i = 1; i < n; i++){
                if(nums[i - 1] == 0 && nums[i] == 0) return true;
            }
            return false;
        }

        /*这里不能通过暴力法去查找*/
        /*我想找到满足(preSum[i] - preSum[j]) % k == 0 -----> preSum[i] % k == preSum[j] % k -----> 快速找数 ---->哈希*/
        //<前缀和取余结果，对应的前缀和下标>
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i <= n; i++){
            mp[preSum[i] % k].push_back(i);
        }

        for(int i = 2; i <= n; i++){
            for(auto index : mp[preSum[i] % k]){
                /*存在取余结果相等且长度大于2*/
                if(index < i - 1) return true;
            }
        }
        return false;
    }
};