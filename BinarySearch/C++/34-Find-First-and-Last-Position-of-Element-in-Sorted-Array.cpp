class Solution {
public:
    vector<int> ans;
    vector<int> searchRange(vector<int>& nums, int target) {
        ans.push_back(left_bound(nums, target));
        ans.push_back(right_bound(nums, target));
        return ans;
    }

    int left_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size();
        while(left < right){
            int mid = (left + right) >> 1;
            if(nums[mid] == target){
                if(mid == 0 || (nums[mid] > nums[mid - 1])){
                    return mid;
                }
                right = mid;
            }
            else if(nums[mid] > target){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return -1;
    }

    int right_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size();
        while(left < right){
            int mid = (left + right) >> 1;
            if(nums[mid] == target){
                if(mid == nums.size() - 1 || (nums[mid] < nums[mid + 1])){
                    return mid;
                }
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return -1;
    }
};