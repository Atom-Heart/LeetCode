class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2, 0);

        int diff = 0;
        /*求出那两个只出现了一次的数的异或值*/
        for(int num : nums){
            diff ^= num;
        }
        /*因为只出现一次的两个数不相等，所以它们的异或值必然不为0，说明这个两个数异或的结果至少有一位为1
        现在我找出异或结果第一个为1的位置，然后通过这个位置把数组分为两个部分*/
        diff = (diff & (diff - 1)) ^ diff;

        for(int num : nums){
            if((num & diff) == 0){
                ans[0] ^= num;
            }
            else{
                ans[1] ^= num;
            }
        }
        return ans;
    }
};