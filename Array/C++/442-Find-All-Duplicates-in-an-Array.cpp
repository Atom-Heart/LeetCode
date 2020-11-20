/*原地修改元素为负数做访问标记*/
/*因为1<=a[i]<=n,这里的n是数组长度，这一点很重要，说明元素值可以映射为下标*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int index = abs(nums[i]);//将元素当作数组下标
            if(nums[index - 1] < 0) ans.push_back(index);//已经访问过一次了
            else nums[index - 1] = -nums[index - 1];
        }
        return ans;
    }
};