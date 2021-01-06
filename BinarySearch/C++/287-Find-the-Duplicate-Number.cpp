/*抽屉原理，可以把题目理解成：有编号为1~n的n个抽屉，有n+1个苹果，哪个抽屉里的苹果不止一个（只会有一个抽屉的苹果不止一个）*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right) / 2;
            
            int cnt = 0;
            for(int num : nums){
                if(num >= left && num <= mid) cnt++;
            }
            if(cnt > mid - left + 1) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};