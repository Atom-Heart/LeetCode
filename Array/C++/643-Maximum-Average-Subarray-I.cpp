class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size() + 1;
        vector<double> preSum(n, 0);
        for(int i = 1; i < preSum.size(); i++){
            preSum[i] = preSum[i - 1] + (double)nums[i - 1];
        }
        int left = 1, right = k;
        double ans = INT_MIN;
        while(right < n){
            double x = (preSum[right] - preSum[left - 1]) / k;
            ans = max(ans, x);
            right++;
            left++;
        }
        return ans;
    }
};