class Solution {
public:
    /*
    *1.三个整数相乘
    *2.两个负数乘一个正数
    *3.三个负数相乘
    */
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int x = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int y = nums[n - 1] * nums[0] * nums[1];
        return max(x, y);
    }
};