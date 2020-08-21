class Solution {
public:
    /*                    0 1 2 3*/
    /*举个例子：输入数组是0 3 1 4,异或运算是一个数和自己做异或运算，结果是0;和零做运算的结果是自己*/
    /*只要把所有元素和索引做异或运算，那么剩下的就是那个缺失的数*/
    /*4^(0 ^ 0) ^ (1 ^ 3) ^ (2 ^ 1) ^ (3 ^ 4),然后通过交换律和集合率得到 2 ^ 0 = 2*/
    /*int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;//这是补上的那个下标
        for(int i = 0; i < nums.size(); i++){
            res = res ^ i ^ nums[i];
        }
        return res;
    }*/

    
    /*如果每个下标都减去当前元素，那么剩下的值必然是缺失的数字*/
    int missingNumber(vector<int>& nums){
        int n = nums.size();
        int res = n;
        for(int i = 0; i < n; i++){
            res += (i - nums[i]);   
        }
        return res;
    }
};