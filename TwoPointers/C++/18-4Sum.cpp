/*方法一：回溯（超时）*/
class Solution {
public:
    vector<int> route;
    vector<vector<int>> ans;
    set<vector<int>> st;
    int n;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        n = target; 
        sort(nums.begin(), nums.end());
        backTracking(nums, 0);
        for(auto it = st.begin(); it != st.end(); it++) ans.push_back(*it);
        return ans;   
    }
    void backTracking(vector<int>& nums, int begin){
        if(route.size() == 4){
            int sum = 0;
            for(int num : route) {
                sum += num;
            }
            if(sum == n && st.find(nums) == st.end()) {
                st.insert(route);
            }
            return;
        }

        for(int i = begin; i < nums.size(); i++){
            route.push_back(nums[i]);
            backTracking(nums, i + 1);
            route.pop_back();
        }
    }
};

/*方法二：双指针*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size() - 3; i++){//后面最少剩三个数
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < nums.size() - 2; j++){//后面最少剩两个数
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;//去重

                int left = j + 1, right = nums.size() - 1;
                while(left < right){
                    if(nums[i] + nums[j] + nums[left] + nums[right] == target){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        while(left < right && nums[left] == nums[left + 1]) left++;//去重
                        while(left < right && nums[right] == nums[right - 1]) right--;//去重
                        left++;
                        right--;
                    }
                    else if(nums[i] + nums[j] + nums[left] + nums[right] > target){
                        right--;
                    }
                    else{
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};