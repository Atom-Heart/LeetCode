class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    int len = nums.size();
    if (len < 3) return false;
    int small = INT_MAX, mid = INT_MAX;
    for (auto num : nums) {
      if (num <= small) {
        small = num;
      } else if (num <= mid) {
        mid = num;
      } 
      else if (num > mid) {
        return true;
      }
    }
    return false;    
  }
};

作者：fxxuuu
链接：https://leetcode-cn.com/problems/increasing-triplet-subsequence/solution/c-xian-xing-shi-jian-fu-za-du-xiang-xi-jie-xi-da-b/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。