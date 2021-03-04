class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        /*nums[i]应该放在nums[i] - 1这个位置上*/
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] >= 1 && nums[i] <= len && nums[nums[i] - 1] != nums[i]){
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        /*搜索的区间是[1, nums.size() + 1]*/
        /*举个极端例子[1,2,3,4]，那么答案应该是5*/
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};