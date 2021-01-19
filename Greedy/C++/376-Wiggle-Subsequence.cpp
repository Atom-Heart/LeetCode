class Solution {
public:
    /*贪心策略：1.先删除数组中的连续重复元素 2.选择左右端点和区间中的极值*/
    int wiggleMaxLength(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        if(nums.size() <= 2) return nums.size();

        int ans = 2;
        for(int i = 1; i + 1 < nums.size(); i++){
            int a = nums[i - 1], b = nums[i], c = nums[i + 1];
            if(a > b && c > b || a < b && c < b) ans++;
        }
        return ans;
    }
};