class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left < right){
            int mid = (left + right) >> 1;
            if(nums[mid] >= x) right = mid;
            else left = mid + 1;
        }
        
        left = right - 1;
       // cout<<left<<" "<<right<<endl;
        while(k > 0 && left >= 0 && right < n){
            if(abs(nums[left] - x) > abs(nums[right] - x)){
                ans.push_back(nums[right]);
                right++;
            }
            else{
                ans.push_back(nums[left]);
                left--;
            }
            k--;
        }

        while(k > 0){
            if(left >= 0){
                ans.push_back(nums[left]);
                left--;
            }
            if(right < n){
                ans.push_back(nums[right]);
                right++;
            }
            k--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};