class Solution {
public:
    /*这道题主要在于明白为什么含有重复元素的时候不能用二分*/
    bool search(vector<int>& nums, int target) {
        /*先删除结点相等的部分*/
        int right = nums.size() - 1;
        while(right >= 0 && nums[right] == nums[0]) right--;
        if(right < 0) return nums[0] == target;
        //cout<<right<<endl;


        /*先找到nums中的最小值的位置*/
        int back = nums[right];
        int left = 0, end = right;
        while(left < right){
            int mid = (left + right) >> 1;
            if(nums[mid] <= back && nums[mid] <= nums[mid + 1]) right = mid;
            else left = mid + 1;
        }

        if(target >= nums[left] && target <= back){
            right = end;
        }
        else{
            right = left - 1;
            left = 0;
        }

        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return nums[left] == target;
    }
};