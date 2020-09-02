/*这类题利用的是数组元素和下标的索引关系，需要在原数组上标记是否被映射过，没有被映射过则说明缺失该数字*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            int index = abs(nums[i]) - 1;//将元素1···n映射至下标0···n-1
            if(nums[index] > 0){
                nums[index] = -nums[index];
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                res.push_back(i + 1);//再将下标还原成元素
            }
        }
        return res;
    }
};