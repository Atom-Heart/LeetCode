class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;

        int len = 1;
        int left = 1, right = 1;

        while(right < nums.size()){
            if(nums[right] == nums[right - 1]){
                right++;
            }
            else{
                nums[left] = nums[right];
                left++;
                right++;
                len++;
            }
        }
        return len;
    }
};