class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right) >> 1;
            if(nums[mid] <= nums.back()) right = mid;
            else left = mid + 1;
        }
        return nums[left];
        

    }
};