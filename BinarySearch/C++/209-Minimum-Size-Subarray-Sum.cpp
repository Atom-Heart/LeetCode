class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        for(int i = 1; i <= n; i++) preSum[i] = preSum[i - 1] + nums[i - 1];
        
        
        int ans = INT_MAX;
        for(int i = 1; i <= n; i++){
            int left = i, right = n;
            if(preSum[right] - preSum[left - 1] < s) break;

            int flag = left;
            int x = preSum[left - 1];

            while(left < right){
                int mid = (left + right) >> 1;
                if(preSum[mid] - x >= s) right = mid;
                else left = mid + 1;
            }
            //cout<<flag<<" "<<right<<" ";
            ans = min(ans, right - flag + 1);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};