class Solution {
public:
    /*现在需要找到重复的元素和缺失的元素*/
    /*0 1 2 3*/
    /*1 2 2 4*///如果把每个元素都减一
    /*0 1 1 3*/
    /*这样让索引和元素值可以一一对应，遍历所有元素值，index = nums[i] - 1， nums[index] *= -1，意思就是把出现过的索引的元素变为相反数，那么重复的元素就会被映射到一个负数上*/
    /*题目是让判断1...n中的重复或缺失元素，为了方便理解，可以先简化成0...n-1，这样每个元素就和一个数组索引完全对应了，如果某个数重复了，那么就会被映射到同一个索引，而且有一个索引没有数字对应过    去。通过将每个索引对应的数变为负数，表示这个索引已经被对应过了*/

    /*0 1 2 3 4*/
    /*0 4 1 4 2*/
    /*0 -> 0   1 -> 2  2 -> 4  3 -> 2 4 -> 1*/
    /*1对应2， 3也对应2，重复*
    /*3没有数字对应*/
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = -1;
        for(int i = 0; i < n; i++){
            int index = abs(nums[i]) - 1;//这里取的是索引，有可能被之前的操作置为相反数，所以要取绝对值
            if(nums[index] < 0){
                dup = abs(nums[index]);//被映射了两次，说明这个数是重复的
            }
            else{
                nums[index] *= -1;//标记已经被映射过了
            }
        }

        int missing = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                missing = i + 1;//因为nums[0...n-1]存放的是索引,0...n-1是被映射的数，如果nums[i]是正数的话，说明i没有元素对应
            }
        }
        return {dup, missing};
    }
};

/*对于这种数组问题，关键点在于元素和索引是成对出现的，常用的方法是“排序”，“异或”，“映射”*/
/*映射的思路就是将每个索引和元素对应起来，通过正负号记录某个元素是否被映射*/



class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int x, y;
        int n = nums.size();
        vector<int> hash(n + 1, 0);
        for(int num : nums){
            hash[num]++;
        }
        for(int i = 1; i <= n; i++){
            if(hash[i] == 0) y = i;
            if(hash[i] == 2) x = i;
        }
        return {x, y};
    }
};