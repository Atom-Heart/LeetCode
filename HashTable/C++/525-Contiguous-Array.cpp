class Solution {
public:
    /*
    *定终点，向前枚举起点，从而得到一个区间。
    *不需要知道每个区间内具体有多少个0和1，只需要记录0和1的差值就可以了；s[i]表示1~i的差值，s[j]表示1~j的差值（i>j），那么(j, i)的差值就是s[i] - s[j - 1]
    *这道题主要难点在于很难想到0和1的差值也可以使用类似前缀和的技巧
    */
    int findMaxLength(vector<int>& nums) {
        /*差值，下标*/
        unordered_map<int, int> mp;
        mp[0] = 0;
        int n = nums.size();
        int zero = 0, one = 0, ans = 0;
        for(int i = 1; i <= n; i++){
            if(nums[i - 1] == 0) zero++;
            else one++;

            int s = zero - one;
            /*如果map存在s，那么这个mp[s]保存的一定是s出现最早的位置*/
            if(mp.count(s)) ans = max(ans, i - mp[s]);
            else mp[s] = i;
        }
        return ans;
    }
};