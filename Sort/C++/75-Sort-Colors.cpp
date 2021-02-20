class Solution {
public:
    /*
    * 0~j-1都是0
    * j~i-1是1
    * k+1~n-1是2
    */

    /*这个题反正是比较巧妙的，这个区间划分还是要多想想，为什么i <= k就退出for循环*/
    void sortColors(vector<int>& nums) {
        for(int i = 0, j = 0, k = nums.size() - 1; i <= k;){
            if(nums[i] == 0) swap(nums[i++], nums[j++]);
            else if(nums[i] == 2) swap(nums[i], nums[k--]);
            else i++;
        }
    }
};