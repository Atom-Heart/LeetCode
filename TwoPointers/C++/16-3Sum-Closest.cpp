class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0x7f7f7f7f;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i + 2 < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while(left < right){
                int num = nums[left] + nums[right] + nums[i];
                if(abs(num - target) < abs(ans - target)){
                    ans = num;
                }
                if(num == target) return num;
                else if(num > target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return ans;
    }
};