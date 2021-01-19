class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right) >> 1;
            if(nums[mid] <= nums.back()) right = mid;//?
            else left = mid + 1;
        }

        if(target <= nums.back()) right = nums.size() - 1;
        else{
            right--;;
            left = 0;
        }
        while(left < right){
            int mid = (left + right) >> 1;
            if(nums[mid] >= target) right = mid; //?
            else left = mid + 1;
        }
        return (nums[left] == target) ? left : -1;
    }
};