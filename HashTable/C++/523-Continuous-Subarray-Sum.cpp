class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        for(int i = 1; i <= n; i++){
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }

        if(k == 0){
            for(int i = 1; i < n; i++){
                if(nums[i] == 0 && nums[i - 1] == 0) return true;
            }
            return false;
        }

        unordered_set<int> hash;
        /*因为长度最小为2，所以带搜索的区间是[i - 1, i], [i - 2, i], ```, [1, i]*/
        for(int i = 2; i <= n; i++){
            hash.insert(preSum[i - 2] % k);//把[i - 1, i]加入hash
            if(hash.count(preSum[i] % k)) return true;
        }
        return false;
    }
};