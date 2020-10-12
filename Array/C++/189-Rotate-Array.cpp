/*方法一：暴力*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for(int i = 0; i < k; i++){
            int num = nums[nums.size() - 1];
            for(int j = nums.size() - 2; j >= 0; j--){
                nums[j + 1] = nums[j];
            }
            nums[0] = num;
        }
    }
};

/*方法二：三次翻转*/
class Solution {
public:
    void reverse(vector<int>& nums, int left, int right){
        while(left < right){
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k == 0) return;
        ::reverse(nums.begin(), nums.end());
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};