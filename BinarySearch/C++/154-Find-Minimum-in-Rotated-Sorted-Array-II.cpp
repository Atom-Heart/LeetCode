class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;
        int right = n;
        while(right >= 0 && nums[right] == nums[0]) right--;
        if(right < 0) return nums[0];
        
        int left = 0, end = nums[right];
        while(left < right){
            int mid = (left + right) >> 1;
            if(nums[mid] <= end) right = mid;
            else left = mid + 1;
        }
        return nums[left];
    }
};