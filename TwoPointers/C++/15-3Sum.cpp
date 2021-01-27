class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i + 2 < n; i++){
            if(nums[i] > 0) break;

            int target = -nums[i];
            vector<int> cur;
            cur.push_back(nums[i]);
            int left = i + 1, right = n - 1;

            if(i > 0 && nums[i] == nums[i - 1]) continue;

            while(left < right){
                if(nums[left] + nums[right] == target){
                    ans.push_back({nums[i], nums[left], nums[right]});

                    while(left < right && nums[left] == nums[left + 1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right - 1]){
                        right--;
                    }
                    left++;
                    right--;
                }
                else if(nums[left] + nums[right] > target){
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