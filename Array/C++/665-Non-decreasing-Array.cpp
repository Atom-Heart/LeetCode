class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() < 3) return true;
        int cnt = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            /*那当前的数和后面的数比较*/
            if(nums[i] > nums[i + 1]){
                cnt++;
                if(cnt > 1) break;
                /*不是第一个数且这个数前面的数大于这个数后面的数：685*/
                if(i - 1 >= 0 && nums[i - 1] > nums[i + 1]){
                    nums[i + 1] = nums[i];//修改后面的数
                }
                else{
                    nums[i] = nums[i + 1];//修改当前数
                }
            }
        }
        return cnt <= 1;
    }
};