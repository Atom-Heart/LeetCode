class Solution {
public:
    /*
    *主要难点在于存在负数；当迭代到nums[i]时：
    *要算出以nums[i]结尾的最大值和最小值
    *如果nums[i]>0，以nums[i]结尾的最大值是nums[i] * f[i - 1] or nums[i];否则最小值是nums[i] * g[i - 1] or nums[i]
    *如果nums[i]<0，最大值是nums[i] * g[i - 1] or nums[i];最小值是nums[i] * f[i - 1] or nums[i]
    *
    */
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int f = nums[0], g = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int fa = nums[i] * f, ga = nums[i] * g, a = nums[i];
            f = max(a, max(fa, ga));
            g = min(a, min(fa, ga));
            ans = max(ans, f);
        }
        return ans;

    }
};