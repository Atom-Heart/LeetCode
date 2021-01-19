class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) sum += nums[i];
        int target = sum - x;
        int left = 0, right = 0, cur = 0;
        int n = nums.size(), ans = INT_MIN;
        while(right < n){
            cur += nums[right];
            right++;
            while(cur >= target && left < n){
                if(cur == target){
                    ans = max(ans, right - left);
                }
                cur -= nums[left];
                left++;   
            }
        }
        return ans == INT_MIN ? -1 : n - ans;
    }
};