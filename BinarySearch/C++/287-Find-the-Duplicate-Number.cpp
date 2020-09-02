/*二分搜索*/
/*我们知道二分搜索要求有序，但给定数组不是有序的，那么怎么用二分搜索呢？*/
/*虽然原数组不是有序的，但我们知道重复的那个数字肯定是1~n中的一个，而1·····n就是一个有序序列，因此我们可以对1·····n进行二分查找*/
/*mid = (1 + n) / 2，接下来判断最终答案是在[1, mid]中还是在[mid + 1, n]中，我们只需要统计原数组中小于等于mid的个数，记为count*/
/*如果count>mid，根据鸽巢原理，再[1, mid]中的数字个数超过了mid，所以一定有一个重复数字*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            for(int i = 0; i <= mid; i++)
        }
    }
};