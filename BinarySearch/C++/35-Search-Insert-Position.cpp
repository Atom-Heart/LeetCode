class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty() || nums.back() < target) return nums.size();
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right) >> 1;
            if(nums[mid] < target) left = mid + 1;
            else r = mid;
        }
        return left;
    }
};